#pragma once

#include <atomic>

#include "../operator/FusionOperator.h"
#include "../query/Query.h"
#include "../utils/Utils.h"
#include "CheckpointCoordinator.hpp"

enum ExecuteState { DEFAULT, INSTRUMENTED, OPTIMIZED };

class ChannelRuntime {
    private:
        Query *query;
        ExecuteState currentState = DEFAULT;
        std::vector<std::shared_ptr<EventQueue>> queues;
        std::vector<std::thread> workThreads;

        // checkpoint related
        // CheckpointCoordinator* checkpointCoordinator;

        static void runWorker(ChannelRuntime *runtime, FusionOperator *fusion_operator, int threadId);

    public:
        ChannelRuntime();
        ChannelRuntime(size_t checkpointInterval);
        ~ChannelRuntime();

        void execute(Query *query);
        bool isRunning();
};