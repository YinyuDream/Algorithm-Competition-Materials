#pragma once

#include <cstring>
#include <iostream>

class SystemConf {
private:
    SystemConf(){};

public:
    static unsigned int BUNDLE_SIZE;
    static int WATERMARK_INTERVAL;
    static int CHECKPOINT_INTERVAL;
    static int WORKER_THREADS;
    static int QUERY_NUM;
    static int PARALLEL_SOURCE;
    static int TEST_CASE;
    static std::string path;
    static std::string path1;
    static std::string path2;
    static std::string tmpFileName;
    static std::string tmpDirectory;

    static SystemConf &getInstance() {
        static SystemConf instance;
        return instance;
    }

    SystemConf(SystemConf const &) = delete;
    void operator=(SystemConf const &) = delete;

    void dump() {
        std::string s = "=== [System configuration dump] ===\n";

        s.append("=== [End of system configuration dump] ===");

        std::cout << s << std::endl;
    }
};