#pragma once

#include <cstdio>
#include <string>

#include "Event.h"
#include "concurrentqueue.h"

using UnixTimestamp = unsigned long long;
inline void emit(const Event &event) {
    std::cout << (event).to_string() << std::endl;
}

using EventQueue = moodycamel::ConcurrentQueue<Event>;

enum InputType { StandardInput,
                 CSVFile,
                 BinaryFile,
                 Socket,
                 Memory,
                 UNDEFINED_INPUT_TYPE };
enum OutputType { StandardOutput,
                  File,
                  UNDEFINED_OUTPUT_TYPE };
enum WindowType { TUMBLING,
                  SLIDING,
                  SESSION };

void bindProcess(const int core_id);
void bindProcess(std::thread &thread, const int id);

class Time {
public:
    int hours;
    int minutes;
    int seconds;
    size_t time;

    Time() {}
    Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}

    std::string to_string() const { return std::to_string(this->time); }
};
