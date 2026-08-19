#include <iostream>

#include "../utils/SystemConf.h"
#include "SinkOperator.h"

SinkOperator::SinkOperator(OutputType outputType) : type(outputType) {}

SinkOperator::SinkOperator(OutputType outputType, TupleSchema outputSchema)
    : type(outputType), outputSchema(outputSchema) {}

SinkOperator::~SinkOperator() {}

std::string SinkOperator::to_string() { return "Sink"; }

Event SinkOperator::process_data(Event record) {
    record.printDebug();
    if (type == OutputType::StandardOutput) {
        switch (record.getType()) {
        case EventType::RECORD:
            std::cout << "##### Event result" << std::endl;
            for (auto iter : record.values) {
                std::cout << iter << " ";
            }
            std::cout << std::endl;
            break;
        case EventType::CHECKPOINTBARRIER:
        case EventType::WATERMARK:
        case EventType::NOVALUE:
        default:
            break;
        }
    }
    return record;
}