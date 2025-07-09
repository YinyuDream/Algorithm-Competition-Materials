#include <algorithm>
#include <sstream>
#include <string>

#include "MapOperator.h"

Event Transform::convert(Event record) {
    // construct new Schema and insert value
    auto before_fileds = record.fields;
    auto before_values = record.values;

    // delete before values
    std::sort(subtractFieldIndex.rbegin(), subtractFieldIndex.rend());
    for (auto index : subtractFieldIndex) {
        if (index < before_fileds.size()) {
            before_fileds.erase(before_fileds.begin() + index);
        }
        if (index < before_values.size()) {
            before_values.erase(before_values.begin() + index);
        }
    }

    // insert new element
    for (auto field : addFields) {
        before_fileds.push_back(field);
    }
    for (auto value : values) {
        before_values.push_back(value);
    }

    Event ans = Event(before_fileds, before_values);
    ans.timestamp = record.timestamp;
    return ans;
}

MapOperator::MapOperator(Mapper &mapper, Operator *input) : mapper(mapper), input(input) {
    leftChild = NULL;
    rightChild = NULL;
    input->parent = this;
    name = "Map";
}

std::string MapOperator::to_string() { return "Map"; }

MapOperator::~MapOperator() { delete input; }

Event MapOperator::process_data(Event record) {
    switch (record.getType()) {
    case EventType::CHECKPOINTBARRIER:
        return record;
    case EventType::WATERMARK:
        return record;
    case EventType::RECORD: {
        Event result = mapper.convert(record);
        return result;
        break;
    }
    case EventType::NOVALUE:
        return record;
    default:
        return record;
    }
}