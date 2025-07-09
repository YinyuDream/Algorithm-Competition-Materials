#include "FilterOperator.h"

std::string Equal::to_string() { return "Equal"; }

bool Equal::process_data(Event &data) {
    // data.printDebug();
    if (data.getFieldValue(fieldName) == value) {
        return true;
    }
    return false;
}

FilterOperator::FilterOperator(Predicate &predicate, Operator *input)
    : predicate(predicate), input(input) {
    leftChild = NULL;
    rightChild = NULL;
    input->parent = this;
    name = "Filter";
}

FilterOperator::~FilterOperator() { delete input; }

std::string FilterOperator::to_string() { return "Filter"; }

Event FilterOperator::process_data(Event record) {
    switch (record.getType()) {
    case EventType::WATERMARK:
        return record;
    case EventType::CHECKPOINTBARRIER:
        return record;
    case EventType::RECORD:
        if (predicate.process_data(record)) {
            return record;
        } else {
            return Event(EventType::NOVALUE);
        }
    default:
        return record;
    }
}