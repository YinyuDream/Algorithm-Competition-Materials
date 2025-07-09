#pragma once

#include "Operator.h"

class Predicate {
public:
    virtual ~Predicate() {}

    std::string fieldName;
    std::string value;

    virtual std::string to_string() = 0;

    virtual bool process_data(Event &data) = 0;
};

class Equal : public Predicate {
public:
    Equal(std::string fieldName, std::string value) {
        this->fieldName = fieldName;
        this->value = value;
    }

    Equal(std::string fieldName, long value) {
        this->fieldName = fieldName;
        this->value = std::to_string(value);
    }

    Equal(std::string fieldName, Field &field2) {
        this->fieldName = fieldName;
        this->value = "record." + field2.name;
    }

    std::string to_string() override;

    bool process_data(Event &data) override;
};

class FilterOperator : public Operator {
public:
    FilterOperator(Predicate &predicate, Operator *input);
    ~FilterOperator();

    Event process_data(Event record);
    std::string to_string();

private:
    Predicate &predicate;
    Operator *input;
};
