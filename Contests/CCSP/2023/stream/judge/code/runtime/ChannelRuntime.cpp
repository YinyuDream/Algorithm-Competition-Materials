#include <thread>

#include "../operator/WindowOperator.h"
#include "ChannelRuntime.h"

ChannelRuntime::ChannelRuntime() {
    // checkpointCoordinator = new CheckpointCoordinator();
}

ChannelRuntime::ChannelRuntime(size_t checkpointInterval) {
    // checkpointCoordinator = new CheckpointCoordinator(checkpointInterval);
}

ChannelRuntime::~ChannelRuntime() {}

void ChannelRuntime::runWorker(ChannelRuntime *runtime, FusionOperator *fusion_operator, int threadId) {
    // Test WatermarkGenerator, we just use thread 0 for result
    if (SystemConf::getInstance().TEST_CASE == 1) {
        if (threadId != 0) {
            return;
        }
        while (runtime->isRunning()) {
            auto inputEvent = fusion_operator->get_data(threadId);
            if ((inputEvent.getType() == EventType::NOVALUE) || (inputEvent.getType() == EventType::ENDAPPLICATION)) {
                break;
            }
            if (inputEvent.getType() == EventType::WATERMARK) {
                emit(inputEvent);
            }
        }
    } else if (SystemConf::getInstance().TEST_CASE == 2) { // Case 2
        // just for TwoInputWindowOperator* process_watermark
        // 交替获得 channel1 和 channel2 的 Event
        if ((threadId == 0 || threadId == 1)) { // Source Operator
            while (runtime->isRunning()) {
                auto inputEvent = fusion_operator->get_data(threadId);
                if ((inputEvent.getType() == EventType::NOVALUE) || (inputEvent.getType() == EventType::ENDAPPLICATION)) {
                    if (fusion_operator->outputQueue.size()) {
                        fusion_operator->execute(Event(EventType::ENDAPPLICATION), threadId);
                    }
                    break;
                } else if (inputEvent.getType() == EventType::WATERMARK) {
                    fusion_operator->execute(inputEvent, threadId);
                }
            }
        } else if (threadId == 2) { // TwoInputWindowOperator
            auto x = (WindowOperator *)fusion_operator->fusionOperators[0];
            auto windowOperator = createTwoInputWindowOperator(x->window, x->input);

            int currentQueue = 0, nextQueue = 1;
            int inputdone = 0;
            Event event;
            do {
                while (fusion_operator->inputQueue[currentQueue]->try_dequeue(event)) {
                    // 每次成功获得一个元素，就交换位置
                    if ((event.getType() == EventType::WATERMARK)) {
                        windowOperator->process_event(event, currentQueue);
                        if (inputdone == 0) {
                            std::swap(currentQueue, nextQueue);
                        }
                    } else if (event.getType() == EventType::ENDAPPLICATION) {
                        inputdone++;
                        if (inputdone == 1) {
                            std::swap(currentQueue, nextQueue);
                        } else if (inputdone == 2) {
                            return;
                        }
                    }
                }
            } while (true);
        }
    } else if (SystemConf::getInstance().TEST_CASE == 3) { // Case 3
        if ((threadId == 0 || threadId == 1)) {            // Source Operator
            while (runtime->isRunning()) {
                auto inputEvent = fusion_operator->get_data(threadId);
                if ((inputEvent.getType() == EventType::NOVALUE) || (inputEvent.getType() == EventType::ENDAPPLICATION)) {
                    if (fusion_operator->outputQueue.size()) {
                        fusion_operator->execute(Event(EventType::ENDAPPLICATION), threadId);
                    }
                    break;
                } else if ((inputEvent.getType() == EventType::WATERMARK) || (inputEvent.getType() == EventType::RECORD)) {
                    fusion_operator->execute(inputEvent, threadId);
                }
            }
        } else if (threadId == 2) { // TwoInputWindowOperator
            auto x = (WindowOperator *)fusion_operator->fusionOperators[0];
            auto windowOperator = createTwoInputWindowOperator(x->window, x->input);

            int currentQueue = 0, nextQueue = 1;
            int inputdone = 0;
            Event event;
            do {
                while (fusion_operator->inputQueue[currentQueue]->try_dequeue(event)) {
                    // 每次成功获得一个元素，就交换位置
                    if ((event.getType() == EventType::RECORD) || (event.getType() == EventType::WATERMARK)) {
                        windowOperator->process_event(event, currentQueue);
                        if (inputdone == 0) {
                            std::swap(currentQueue, nextQueue);
                        }
                    } else if (event.getType() == EventType::ENDAPPLICATION) {
                        inputdone++;
                        if (inputdone == 1) {
                            std::swap(currentQueue, nextQueue);
                        } else if (inputdone == 2) {
                            return;
                        }
                    }
                }
            } while (true);
        }
    } else if (SystemConf::getInstance().TEST_CASE == 4) { // Case 4 - do_checkpoint
        if ((threadId == 0 || threadId == 1)) {            // Source Operator
            while (runtime->isRunning()) {
                auto inputEvent = fusion_operator->get_data(threadId);
                if ((inputEvent.getType() == EventType::NOVALUE) || (inputEvent.getType() == EventType::ENDAPPLICATION)) {
                    if (fusion_operator->outputQueue.size()) {
                        fusion_operator->execute(Event(EventType::ENDAPPLICATION), threadId);
                    }
                    break;
                }
                fusion_operator->execute(inputEvent, threadId);
            }
        } else if (threadId == 2) { // TwoInputWindowOperator
            auto x = (WindowOperator *)fusion_operator->fusionOperators[0];
            auto windowOperator = createTwoInputWindowOperator(x->window, x->input);

            int currentQueue = 0, nextQueue = 1;
            int inputdone = 0;
            Event event;
            // 先看第一个管道的元素，处理之后看第二个的。每次交换之前查看另一个管道的状态是否是可达的，如果不可达则不交换
            // 初始的时候两个管道的状态都是可达的
            do {
                while (fusion_operator->inputQueue[currentQueue]->try_dequeue(event)) {
                    // 每次成功获得一个元素，就交换位置
                    if ((event.getType() == EventType::RECORD) || (event.getType() == EventType::WATERMARK) || (event.getType() == EventType::CHECKPOINTBARRIER)) {
                        windowOperator->process_event(event, currentQueue);
                        if (inputdone == 0) { // 两个都没结束，且另一个没有阻塞
                            if (windowOperator->isAvailable(nextQueue)) {
                                std::swap(currentQueue, nextQueue);
                            }
                        }
                    } else if (event.getType() == EventType::ENDAPPLICATION) {
                        inputdone++;
                        if (inputdone == 1) {
                            std::swap(currentQueue, nextQueue);
                        } else if (inputdone == 2) {
                            return;
                        }
                    }
                }
            } while (true);
        }
    }
}

bool ChannelRuntime::isRunning() {
    return true;
}

void ChannelRuntime::execute(Query *query) {
    this->query = query;
    this->currentState = DEFAULT;

    // Query::printQueryPlan(*query);

    // Step 1 - construct pipelines/(Fusion Operator) according to the query ()
    std::vector<FusionOperator> pipelines;
    if (query->root == NULL) {
        printf("No root node; cant execute queryplan\n");
    } else {
        auto p = query->current;
        FusionOperator fusionOperator = FusionOperator();
        while (p != NULL) {
            // select pipeline-breaker
            fusionOperator.insert_operator(p);
            if ((p->to_string() == std::string("Window")) || (p->to_string() == std::string("Sink"))) {
                fusionOperator.parallelism = 1;
                pipelines.insert(pipelines.begin(), fusionOperator);
                fusionOperator = FusionOperator();
            }
            p = p->rightChild;
        }
        fusionOperator.parallelism = 2;
        pipelines.insert(pipelines.begin(), fusionOperator);
    }

    // set operators chains
    for (int i = 0; i < int(pipelines.size()) - 1; ++i) {
        pipelines[i].next = &pipelines[i + 1];
    }

    // Step 2 - construct message-passing between pipelines and threads
    for (auto iter = pipelines.begin(); iter != pipelines.end() - 1; ++iter) {
        auto next = iter->next;
        auto parallelism = iter->parallelism;
        if (next != nullptr) {
            for (int i = 0; i < parallelism; ++i) {
                // construct data exchange queue
                auto currentQueue = std::make_shared<EventQueue>();
                queues.push_back(currentQueue);
                auto inputQueue = currentQueue;
                auto outputQueue = currentQueue;

                // set input and output index of fusion operator
                next->inputQueue.push_back(inputQueue);
                iter->outputQueue.push_back(outputQueue);
            }
        }
    }

    auto threads_number = 4;
    auto *threads = new std::thread[threads_number];

    // Step 3 - assign threads to those piplines and execute
    // Execute  - input/output: Memory - EventQueue EventQueue - Memory
    // printf("\n============ start run query ==============\n");
    int threads_idx = 0;
    std::vector<FusionOperator> executeOperators;
    for (auto iter = pipelines.begin(); iter != pipelines.end(); ++iter) {
        auto parallelism = iter->parallelism;
        for (int i = 0; i < parallelism; ++i) {
            FusionOperator *fusion_operator = &(*iter);
            threads[threads_idx] = std::thread(ChannelRuntime::runWorker, this, fusion_operator, threads_idx);
            threads_idx++;
        }
    }

    /* Wait for all threads. */
    for (int i = 0; i < threads_number; i++) {
        threads[i].join();
    }
}
