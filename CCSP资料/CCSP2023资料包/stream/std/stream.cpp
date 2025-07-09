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
    UnixTimestamp maxTimestamp = 0, lastOutput = 0;

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
    maxTimestamp = std::max(maxTimestamp, event.getTimeStamp());
}

/**
 * @brief SourceOperator 每收到 10 个点击事件之后就会调用该方法，若符合条件则生成 Watermark
 */
std::optional<Event> TimeLagWatermarkGenerator::onPeriodicEmit() {
    // TODO (任务一/子任务一)：生成 Watermark
    auto candidate = maxTimestamp - maxTimeLag;
    if (candidate > lastOutput) return {Event(EventType::WATERMARK, lastOutput = candidate)};
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

    UnixTimestamp watermark[2], lastOutput = 0;

public:
    TwoInputWindowOperator(Window &window, Operator *input) : TwoInputWindowOperatorInterface(window, input) {
        watermark[0] = watermark[1] = 0;
    };
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
    auto type = event.getType();
    if (type == EventType::RECORD) {
        auto timestamp = std::stoull(event.getFieldValue("timestamp"));
        auto url = event.getFieldValue("url");
        auto click_count = std::stoi(event.getFieldValue("clickNumber"));
        if (timestamp < lastOutput) return;
        auto window_start = get_window_start_unix_timestamp(event);
        windowState[window_start][url] += click_count;
    } else if (type == EventType::WATERMARK) {
        watermark[channelId] = event.getTimeStamp();
        auto candidate = std::min(watermark[0], watermark[1]);
        if (candidate > lastOutput) {
            while (!windowState.empty() && windowState.begin()->first + window.get_window_length() <= candidate) {
                auto iter = windowState.begin();
                for (auto &kv : iter->second) {
                    auto values = std::vector<std::string>{std::to_string(iter->first), kv.first, std::to_string(kv.second)};
                    emit({recordFields, values});
                }
                windowState.erase(windowState.begin());
            }
            emit({EventType::WATERMARK, lastOutput = candidate});
        }
    } else if (type == EventType::CHECKPOINTBARRIER) {
        auto anotherChannelId = 1 - channelId;
        if (!isAvailable(anotherChannelId)) {
            do_checkpoint(event.getCheckpointId());
            resumeChannel(anotherChannelId);
            emit({EventType::CHECKPOINTBARRIER, event.getCheckpointId()});
        } else {
            prohibitChannel(channelId);
        }
    }
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
    std::cerr << "checkpointId: " << checkpointId << " , path: " << path << std::endl;
    std::ofstream out(path);
    for (auto [window_start, url_click_count] : windowState) {
        for (auto [url, click_count] : url_click_count) {
            out << window_start << " " << url << " " << click_count << std::endl;
        }
    }
    out.close();
}

/**
 * !! DO NOT CHANGE THIS !!
 * @brief 创建 TwoInputWindowOperator
 * @return TwoInputWindowOperatorInterface* 
 */
TwoInputWindowOperatorInterface *createTwoInputWindowOperator(Window &window, Operator *input) { return new TwoInputWindowOperator(window, input); }
