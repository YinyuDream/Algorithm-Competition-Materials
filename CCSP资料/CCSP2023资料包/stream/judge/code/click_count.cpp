#include "benchmark/BenchmarkTest.h"
#include "query/Query.h"
#include "utils/SystemConf.h"
#include "utils/TupleSchema.h"

#include <fstream>
#include <iostream>

const std::string inputMagicStr = "0cb4a093806ff1c311e90414277aab19";
const std::string outputMagicStr = "2994323acd260de5a1447584f0278664";

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::getline(std::cin, line);
    if (line != inputMagicStr) {
        std::cout << "[FATAL] input magic string mismatch!" << std::endl;
        return 0;
    }

    int test_case;
    std::string path1, path2;
    std::cin >> test_case >> path1 >> path2;
    SystemConf::getInstance().TEST_CASE = test_case;
    SystemConf::getInstance().path1 = path1;
    SystemConf::getInstance().path2 = path2;

    auto application = new ClickCountBenchmark();

    std::cout << outputMagicStr << std::endl;
    int result = application->runBenchmark();
    std::cout << outputMagicStr << std::endl;

    delete application;
    return result;
}