#include <iostream>
#include <sstream>
#include <string>

#include "FusionOperator.h"
#include "SinkOperator.h"
#include "SourceOperator.h"

FusionOperator::FusionOperator() {}

FusionOperator::~FusionOperator() {}

void FusionOperator::insert_operator(Operator *op) {
    fusionOperators.insert(fusionOperators.begin(), op);
}

Event FusionOperator::get_data(int threadId) {
    auto res = Event();
    if (inputQueue.size() == 1) {
        auto x = inputQueue[0];
        do {
            while (x->try_dequeue(res)) {
                return res;
            }
        } while (true);
    } else {
        // Read data from Source operator - for Source Operator
        if (fusionOperators[0]->to_string() == "Source") {
            auto source = (SourceOperator *)fusionOperators[0];
            auto event = source->get_data(threadId);
            return event;
        } else {
            printf("[debug] branch 222\n");
        }
    }
    return res;
}

void FusionOperator::execute(Event data, int threadId) {
    auto local_data = data;
    for (auto iter : fusionOperators) {
        auto new_data = iter->process_data(local_data);
        if (new_data.getType() == EventType::NOVALUE) { return; }
        local_data = new_data;
    }
    // get result and print it
    if (outputQueue.size() == 2) {
        // Source-Filter-Map
        auto queue = outputQueue[threadId];
        queue->enqueue(local_data);
    } else if (outputQueue.size() == 1) {
        auto queue = outputQueue[0];
        queue->enqueue(local_data);
    } else {
    }
}

std::string FusionOperator::to_string() {
    return "Fusion Operators";
}

int FusionOperator::size() {
    return fusionOperators.size();
}

void FusionOperator::print_operators() {
    for (auto it : fusionOperators) {
        std::cout << it->to_string() << " ";
    }
    std::cout << std::endl;
}