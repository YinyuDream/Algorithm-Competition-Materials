#include "benchmark/BenchmarkTest.h"
#include "query/Query.h"
#include "utils/TupleSchema.h"

#include <fstream>
#include <iostream>

class ClickCountBenchmark : public BenchmarkTest {
private:
    TupleSchema inputSchema;
    std::vector<char> *m_data = nullptr;

public:
    void createSchema() {
        inputSchema = TupleSchema::create()
                          .addFixSizeField("timestamp", DataType::ULL)
                          .addFixSizeField("ip", DataType::String)
                          .addFixSizeField("url", DataType::String)
                          .addFixSizeField("statusCode", DataType::Int);
    }

    void createQuery() {
        // get input paths.
        paths.push_back(SystemConf::getInstance().path1);
        paths.push_back(SystemConf::getInstance().path2);

        // construct MapOperator - transform
        std::vector<size_t> subtractFieldIndex = {1, 3};
        std::vector<Field> addFields = {Field("clickNumber", DataType::Int)};
        std::vector<std::string> values = {"1"};

        //  定义一个从 2023-10-25 9:00:00 开始的窗口，窗口长度为 10 分钟的窗口（都是 Unix 时间戳形式的表示）
        query = Query::source(inputSchema, paths)
                    .filter(new Equal("statusCode", 200))
                    .map(new Transform(subtractFieldIndex, addFields, values))
                    .window(new TumblingWindow(1698195600, 600))
                    .sink(OutputType::StandardOutput);
    }

    ClickCountBenchmark() {
        name = "CLICK_COUNT";
        createSchema();
        createQuery();
    }
};

int main(int argc, const char **argv) {
    BenchmarkTest *application = nullptr;

    // parse command line
    BenchmarkTest::parseCommandLineArguments(argc, argv);

    // Construct click-count benchamrk
    application = new ClickCountBenchmark();

    // run execute
    int result = application->runBenchmark();

    // delete application;
    return result;
}