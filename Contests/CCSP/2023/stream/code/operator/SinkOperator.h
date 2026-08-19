#pragma once

#include "../utils/Utils.h"
#include "Operator.h"

class SinkOperator : public Operator {
private:
    OutputType type;
    TupleSchema outputSchema;

public:
    SinkOperator(OutputType type);
    SinkOperator(OutputType type, TupleSchema outputSchema);
    ~SinkOperator();

    Event process_data(Event event) override;

    std::string to_string() override;
};