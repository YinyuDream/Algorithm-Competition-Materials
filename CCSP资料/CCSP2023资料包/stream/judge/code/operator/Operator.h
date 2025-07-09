#pragma once

#include <string>

#include "../utils/Event.h"
#include "../utils/TupleSchema.h"

class Operator {
public:
    std::string name;
    int pipelineIndex;
    int parallelism;

    TupleSchema *inputSchema;
    TupleSchema *outputSchema;

    Operator *parent;
    Operator *leftChild;
    Operator *rightChild;

    virtual ~Operator() {}

    virtual Event process_data(Event record) = 0;
    virtual std::string to_string() { return "Operator"; }
};