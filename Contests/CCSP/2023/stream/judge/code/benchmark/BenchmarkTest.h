#pragma once

#include <cstring>

#include "../query/Query.h"
#include "../runtime/ChannelRuntime.h"
#include "../utils/SystemConf.h"

class BenchmarkTest {
public:
    std::string name;
    Query query;
    std::vector<std::string> paths;

    std::string getApplicationName() {
        return name;
    }

    static void parseCommandLineArguments(int argc, const char **argv) {
        int i, j;
        for (i = 1; i < argc;) {
            if ((j = i + 1) == argc) {
                throw std::runtime_error("error: wrong number of arguments");
            }
            if (strcmp(argv[i], "--threads") == 0) {
                SystemConf::getInstance().WORKER_THREADS = std::stoi(argv[j]);
            } else if (strcmp(argv[i], "--query") == 0) {
                SystemConf::getInstance().QUERY_NUM = std::stoi(argv[j]);
            } else if (strcmp(argv[i], "--parallel-source") == 0) {
                SystemConf::getInstance().PARALLEL_SOURCE = std::stoi(argv[j]);
            } else if (strcmp(argv[i], "--watermark-interval") == 0) {
                SystemConf::getInstance().WATERMARK_INTERVAL = std::stoi(argv[j]);
            } else if (strcmp(argv[i], "--checkpoint-interval") == 0) {
                SystemConf::getInstance().CHECKPOINT_INTERVAL = std::stoi(argv[j]);
            } else if (strcmp(argv[i], "--test-case") == 0) {
                if ((std::stoi(argv[j]) < 5) && (std::stoi(argv[j]) > 0)) {
                    SystemConf::getInstance().TEST_CASE = std::stoi(argv[j]);
                } else {
                    std::string argument(argv[j]);
                    throw std::runtime_error("error: unknown test-case  " + argument);
                }
            } else if (strcmp(argv[i], "--paths") == 0) {
                int k;
                if ((k = j + 1) == argc) {
                    throw std::runtime_error("error: wrong number of arguments");
                }
                SystemConf::getInstance().path1 = argv[j];
                SystemConf::getInstance().path2 = argv[k];
                j = k;
            } else {
                std::string argument(argv[i]);
                throw std::runtime_error("error: unknown argument " + argument);
            }
            i = j + 1;
        }
    }

    int runBenchmark(bool terminate = true) {
        ChannelRuntime runtime = ChannelRuntime();
        auto m_query = &query;
        try {
            runtime.execute(m_query);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            exit(1);
        }
        return 0;
    }
};