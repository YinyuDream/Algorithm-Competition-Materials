#pragma once

#include <chrono>
#include <ctime>
#include <optional>

#include "../utils/Event.h"
#include "../utils/Utils.h"

class WatermarkGenerator {
public:
    virtual void onEvent(Event &event) = 0;
    virtual std::optional<Event> onPeriodicEmit() = 0;
};

// 给的例子
class ExampleWatermarkGenerator : public WatermarkGenerator {
private:
    size_t maxTimeLag = 5000; // 5000ms

public:
    ExampleWatermarkGenerator() {}

    void onEvent(Event &event) override {
        // 这种情况下不需要实现该函数
    }

    std::optional<Event> onPeriodicEmit() override {
        // 获取当前时间点
        auto currentTime = std::chrono::system_clock::now();
        // 将时间点转换为时间戳
        std::time_t timestamp = std::chrono::system_clock::to_time_t(currentTime);
        UnixTimestamp unixTimeStamp = static_cast<UnixTimestamp>(timestamp);
        // 滞后于固定处理时间（系统时钟）的WatermarkGenerator
        std::optional<Event> watermark(Event(EventType::WATERMARK, unixTimeStamp - maxTimeLag));
        return watermark;
    }
};

WatermarkGenerator *createWatermarkGenerator();
