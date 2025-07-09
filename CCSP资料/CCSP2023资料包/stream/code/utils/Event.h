#pragma once

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include "TupleSchema.h"

enum EventType { RECORD,
                 WATERMARK,
                 CHECKPOINTBARRIER,
                 NOVALUE,
                 ENDAPPLICATION,
                 ACK,
                 FAILED };

class Event {
private:
public:
    /* data */
    unsigned long long timestamp = 0;
    int checkpointId = -1;
    EventType type = EventType::RECORD;
    std::vector<std::string> values;
    std::vector<Field> fields;

    // construct function
    Event() {}
    Event(EventType type) : type(type) {}
    Event(EventType type, int checkpointId) : type(type), checkpointId(checkpointId) {}
    Event(EventType type, unsigned long long timestamp) : type(type), timestamp(timestamp) {}
    Event(TupleSchema &schema, std::vector<std::string> values)
        : values(values) {
        fields = schema.fields;
    }
    Event(std::vector<Field> fields, std::vector<std::string> values) : fields(fields), values(values) {}
    ~Event() {}

    // write methods
    std::string to_string() const {
        switch (type) {
        case EventType::CHECKPOINTBARRIER: {
            return "CHECKPOINTBARRIER-" + std::to_string(checkpointId);
        }
        case EventType::RECORD: {
            std::string result;
            for (auto value : values) {
                result += value + " ";
            }
            return result;
        }
        case EventType::WATERMARK: {
            return "WATERMARK-" + std::to_string(timestamp);
        }
        default:
            return "";
        };
    }

    // read methods
    EventType getType() {
        return type;
    }

    unsigned long long getTimeStamp() {
        return timestamp;
    }

    int getCheckpointId() {
        return checkpointId;
    }

    std::string getFieldValue(std::string fieldName) {
        std::string ans;
        int index = -1;
        for (int i = 0; i < fields.size(); ++i) {
            if (fields[i].name == fieldName) {
                index = i;
                break;
            }
        }
        if (index >= 0) {
            ans = values[index];
        }
        return ans;
    }

    int length() {
        return values.size();
    }

    // helper methods
    void setNull() {
        type = EventType::NOVALUE;
    }

    void printFieldsName() {
        for (auto field : fields) {
            std::cout << field.name << " ";
        }
        std::cout << std::endl;
    }

    void printWatermark() {
        if (type == EventType::WATERMARK) {
            std::cout << "WATERMARK-" << timestamp << std::endl;
        }
    }

    void printRecord() {
        if (type == EventType::RECORD) {
            for (auto value : values) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    void printCheckpointBarrier() {
        if (type == EventType::CHECKPOINTBARRIER) {
            std::cout << "CHECKPOINTBARRIER-" << checkpointId << std::endl;
        }
    }

    void printDebug() {
        for (int i = 0; i < fields.size(); ++i) {
            switch (fields[i].dataType) {
            case DataType::Boolean:
            case DataType::Char:
            case DataType::String:
                std::cout << fields[i].name << ": String-" << values[i] << " ";
                break;
            case DataType::Int:
                std::cout << fields[i].name << " Int-" << stoi(values[i]) << " ";
                break;
            case DataType::Long:
                std::cout << fields[i].name << " Long-" << stol(values[i]) << " ";
                break;
            case DataType::Double:
                std::cout << fields[i].name << " Double-" << stod(values[i]) << " ";
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
};
