#include <fstream>
#include <map>
#include <optional>

#include "operator/WindowOperator.h"
#include "runtime/WatermarkGenerator.hpp"
#include "utils/SystemConf.h"

class TimeLagWatermarkGenerator : public WatermarkGenerator {
private:
    size_t maxTimeLag = 60; // 1 min

    /* TODO (任务一/子任务一): user-defined data */

public:
    TimeLagWatermarkGenerator() {}
    void onEvent(Event &event) override;
    std::optional<Event> onPeriodicEmit() override;
};

/**
 * @brief SourceOperator 收到点击事件时调用该方法
 * @param event 点击事件，保证类型为 EventType::RECORD 
 */
void TimeLagWatermarkGenerator::onEvent(Event &event) {
    // TODO (任务一/子任务一)：根据点击事件更新内部状态
}

/**
 * @brief SourceOperator 每收到 10 个点击事件之后就会调用该方法，若符合条件则生成 Watermark
 */
std::optional<Event> TimeLagWatermarkGenerator::onPeriodicEmit() {
    // TODO (任务一/子任务一)：生成 Watermark
    return std::nullopt;
}

/**
 * !! DO NOT CHANGE THIS !!
 * @brief 创建 WatermarkGenerator
 * @return WatermarkGenerator* 
 */
WatermarkGenerator *createWatermarkGenerator() { return new TimeLagWatermarkGenerator(); }

class TwoInputWindowOperator : public TwoInputWindowOperatorInterface {
private:
    std::map<UnixTimestamp, std::map<std::string, int>> windowState;

    /* TODO (任务一/子任务二，任务二，任务三): user-defined data */

public:
    TwoInputWindowOperator(Window &window, Operator *input) : TwoInputWindowOperatorInterface(window, input) {};
    ~TwoInputWindowOperator() { delete input; }

    std::string to_string() override { return "TwoInputWindowOperator"; }

    void do_checkpoint(int checkpoint) override;
    void process_event(Event event, int channelId) override;
};

const auto recordFields = std::vector<Field>{Field("timeWindow", DataType::ULL), Field("url", DataType::String), Field("clickNumber", DataType::Int)};

/**
 * @brief 处理输入事件
 * @param event 输入事件
 * @param channelId 输入事件的管道id
 * @details
 * - 对于任务一/子任务二：保证输入 event 是 WATERMARK
 * - 对于任务二：保证输入 event 是 WATERMARK 或 RECORD
 * - 对于任务三：保证输入 event 是 WATERMARK，RECORD 或 CEHCKPOINTBARRIER
 */
void TwoInputWindowOperator::process_event(Event event, int channelId) {
    // TODO (任务一/子任务二，任务二，任务三)：处理输入事件
}



/**
 * @brief 创建快照文件
 * @param checkpointId 快照编号
 */
void TwoInputWindowOperator::do_checkpoint(int checkpointId) {
    // 保存的文件路径为 path
    std::string tmpDirectory = SystemConf::getInstance().tmpDirectory;
    std::string tmpFileName = SystemConf::getInstance().tmpFileName;
    std::string path = tmpDirectory + tmpFileName + "_" + std::to_string(checkpointId);
    // TODO (任务三): 创建快照文件
}

/**
 * !! DO NOT CHANGE THIS !!
 * @brief 创建 TwoInputWindowOperator
 * @return TwoInputWindowOperatorInterface* 
 */
TwoInputWindowOperatorInterface *createTwoInputWindowOperator(Window &window, Operator *input) { return new TwoInputWindowOperator(window, input); }
