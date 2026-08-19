#pragma once

#include "../utils/Utils.h"
#include "Operator.h"

#include <optional>

class Window {
public:
    // TumblingWindow
    UnixTimestamp startUnixTimestamp;
    size_t fixedLength;
    // SessionWindow
    size_t timeout;
    // SlidingWindow
    Time size;
    Time slide;

    virtual UnixTimestamp get_window_start_unix_timestamp(UnixTimestamp timestamp) = 0;
    virtual size_t get_window_length() = 0;
};

class TumblingWindow : public Window {
public:
    TumblingWindow(UnixTimestamp startUnixTimestamp, size_t fixedLength) {
        this->startUnixTimestamp = startUnixTimestamp;
        this->fixedLength = fixedLength;
    }
    size_t get_window_length() { return fixedLength; }
    UnixTimestamp get_window_start_unix_timestamp(UnixTimestamp timestamp) {
        if (timestamp >= startUnixTimestamp) {
            return startUnixTimestamp + ((timestamp - startUnixTimestamp) / fixedLength) * fixedLength;
        }
        return 0;
    }
};

class SlidingProcessingTimeWindow : public Window {
public:
    SlidingProcessingTimeWindow(Time size, Time slide) {
        this->size = size;
        this->slide = slide;
    }
};

class SessionProcessingTimeWindow : public Window {
public:
    SessionProcessingTimeWindow(size_t timeout) {
        this->timeout = timeout;
    }
};

class Aggregate {
public:
    std::string key;
    std::string value;
};

class AggregateSum : public Aggregate {
public:
    AggregateSum(std::string key, std::string value) {
        this->key = key;
        this->value = value;
    }
};

class AggregateAvg : public Aggregate {};

class WindowOperator : public Operator {
public:
    WindowType type;
    Window &window;
    Operator *input;

    WindowOperator(Window &window, Operator *input);
    ~WindowOperator();

    Event process_data(Event event) override;
    void process_data() {}
    std::string to_string() override;
};

class TwoInputWindowOperatorInterface : public WindowOperator {
protected:
    /**
     * 处于禁用状态的管道id
     *
     * 禁用状态：若该双输入算子的某输入管道处于禁用状态，则该 TwoInputWindowOperator 将停止接受该管道的数据，直到该管道解禁
     *
     * 在本题中，管道id的值为 0 或 1
     */
    std::optional<int> prohibitChannelId;

public:
    TwoInputWindowOperatorInterface(Window &window, Operator *input) : WindowOperator(window, input), prohibitChannelId(std::nullopt){};
    ~TwoInputWindowOperatorInterface() { delete input; }
    std::string to_string() override { return "TwoInputWindowOperatorInterface"; }

    /**
     * @brief 定位事件 Event 的所属窗口
     * @param event 点击事件 
     * @return UnixTimestamp 
     */
    UnixTimestamp get_window_start_unix_timestamp(Event &event) {
        if (event.getType() == EventType::RECORD) {
            return window.get_window_start_unix_timestamp(event.getTimeStamp());
        }
        return -1;
    }

    /**
     * @brief 将 channelId 对应的管道禁用
     * @param channelId 
     */
    void prohibitChannel(int channelId) {
        if ((channelId != 0) && (channelId != 1)) { return; }
        if (!prohibitChannelId.has_value()) { prohibitChannelId = channelId; }
    }

    /**
     * @brief 恢复接受从 channelId 对应的管道来的数据
     * @param channelId 
     */
    void resumeChannel(int channelId) {
        if ((channelId != 0) && (channelId != 1)) { return; }
        if (prohibitChannelId.has_value()) {
            if (prohibitChannelId.value() == channelId) {
                prohibitChannelId = std::nullopt;
            }
        }
    }

    /**
     * @brief 查看 channelId 对应的管道是否处于禁用状态
     * @param channelId
     */
    bool isAvailable(int channelId) {
        if (prohibitChannelId.has_value()) {
            if (prohibitChannelId.value() == channelId) {
                return false;
            }
        }
        return true;
    }

    virtual void do_checkpoint(int checkpoint) = 0;
    virtual void process_event(Event event, int channelId) = 0;
};

TwoInputWindowOperatorInterface *createTwoInputWindowOperator(Window &window, Operator *input);
