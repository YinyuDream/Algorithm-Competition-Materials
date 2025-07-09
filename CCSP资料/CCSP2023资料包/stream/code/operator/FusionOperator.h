#pragma once

#include <memory>
#include <vector>

#include "../utils/Utils.h"
#include "Operator.h"

class FusionOperator : public Operator {
public:
    FusionOperator();
    ~FusionOperator();

    int parallelism = 0;
    std::vector<std::shared_ptr<EventQueue>> inputQueue;
    std::vector<std::shared_ptr<EventQueue>> outputQueue;
    FusionOperator *next = nullptr;

    void insert_operator(Operator *op);
    int size();

    std::string to_string();
    Event get_data(int threadId);
    void execute(Event data, int threadId);
    Event process_data(Event data) { return data; }
    std::vector<Operator *> fusionOperators;

    // helper methods
    void print_operators();
};