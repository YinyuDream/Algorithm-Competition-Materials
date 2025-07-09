#include "SystemConf.h"

unsigned int SystemConf::BUNDLE_SIZE = 2 * 64 * 1024;
int SystemConf::WORKER_THREADS = 1;
int SystemConf::QUERY_NUM = 0;
int SystemConf::CHECKPOINT_INTERVAL = 0;
int SystemConf::WATERMARK_INTERVAL = 5000;
int SystemConf::PARALLEL_SOURCE = 1;
int SystemConf::TEST_CASE = 1;
std::string SystemConf::path = "";
std::string SystemConf::path1 = "../data/1-0.in";
std::string SystemConf::path2 = "../data/1-1.in";
std::string SystemConf::tmpFileName = "CLICK_COUNT_CHECKPOINT";
std::string SystemConf::tmpDirectory = "./";
