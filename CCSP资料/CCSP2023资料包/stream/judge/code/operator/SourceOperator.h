#pragma once

#include "../runtime/WatermarkGenerator.hpp"
#include "../utils/Utils.h"
#include "Operator.h"

class SourceOperator : public Operator {
private:
    InputType type;
    int parallelism;

    // Input Data related
    TupleSchema &inputSchema;
    std::vector<std::string> paths;
    std::vector<size_t> currentDataIndexs;
    std::vector<std::vector<std::vector<std::string>>> datas;

    // Watermark related
    std::vector<WatermarkGenerator *> watermarkGenerators;
    std::vector<size_t> watermarkIndexs;

    // Checkpoint related
    std::vector<size_t> checkpointIndexs;
    std::vector<int> checkpointIds;

public:
    SourceOperator(TupleSchema &inputSchema);
    SourceOperator(InputType inputType, TupleSchema &inputSchema, std::vector<std::string> paths);
    ~SourceOperator();

    void loadInMemoryData();
    Event get_data(int threadId);
    Event process_data(Event event) override;

    std::string to_string() override;
};