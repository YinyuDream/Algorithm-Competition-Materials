#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

#include <optional>

#include "../utils/SystemConf.h"
#include "SourceOperator.h"

SourceOperator::SourceOperator(TupleSchema &inputSchema)
    : inputSchema(inputSchema) {}

SourceOperator::SourceOperator(InputType inputType, TupleSchema &inputSchema,
                               std::vector<std::string> paths)
    : type(inputType), inputSchema(inputSchema), paths(paths) {
    this->parallelism = paths.size();
    this->loadInMemoryData();
};

SourceOperator::~SourceOperator() {}

std::string SourceOperator::to_string() { return "Source"; }

void SourceOperator::loadInMemoryData() {
    // read data from csv file and save them in the memory
    size_t len = SystemConf::getInstance().BUNDLE_SIZE;

    for (auto path : paths) {
        // std::cout << "reading file:" << path << std::endl;
        std::ifstream file(path);
        std::string line;
        unsigned long idx = 0;
        std::vector<std::vector<std::string>> data;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::vector<std::string> words{std::istream_iterator<std::string>{iss},
                                           std::istream_iterator<std::string>{}};
            data.push_back(words);
            idx++;
        }
        datas.push_back(data);
        currentDataIndexs.push_back(0);

        // construct new WatermarkGenerator
        watermarkGenerators.push_back(createWatermarkGenerator());
        watermarkIndexs.push_back(0);
        checkpointIndexs.push_back(0);
        checkpointIds.push_back(0);
    }
}

Event SourceOperator::get_data(int threadId) {
    if (threadId >= currentDataIndexs.size()) {
        return Event(EventType::ENDAPPLICATION);
    }
    if (currentDataIndexs[threadId] < datas[threadId].size()) {
        // Step 1 - generate Event::Watermark;
        if ((watermarkIndexs[threadId]) && (watermarkIndexs[threadId] % 10 == 0)) {
            watermarkIndexs[threadId] = 0;
            auto res = watermarkGenerators[threadId]->onPeriodicEmit();
            if (res.has_value()) {
                return res.value();
            }
        }

        // Step 2 - generate Event::CheckpointBarrier
        if ((checkpointIndexs[threadId]) && (checkpointIndexs[threadId] % 100 == 0)) {
            checkpointIndexs[threadId] = 0;
            // std::cout << "debug: thread" << threadId << "checkpointId" << checkpointIds[threadId] << std::endl;
            auto res = Event(EventType::CHECKPOINTBARRIER, checkpointIds[threadId]);
            checkpointIds[threadId]++;
            return res;
        }

        // Step 3 - get Event::record from data.
        auto event = Event(inputSchema, datas[threadId][currentDataIndexs[threadId]]);
        UnixTimestamp tmp_timestamp = std::stoull(event.getFieldValue("timestamp"));
        event.timestamp = tmp_timestamp;
        watermarkGenerators[threadId]->onEvent(event); // update Watermark timestamp;
        currentDataIndexs[threadId]++;
        watermarkIndexs[threadId]++;
        checkpointIndexs[threadId]++;
        return event;
    } else {
        return Event(EventType::ENDAPPLICATION);
    }
}

Event SourceOperator::process_data(Event record) {
    return record;
}