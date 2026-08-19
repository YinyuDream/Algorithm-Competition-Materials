#pragma once

#include "Operator.h"

class Mapper {
public:
    Mapper() {}
    // string value
    Mapper(std::string fieldId, std::string value, std::string outputField)
        : fieldId(fieldId), value("\"" + value + "\""), outputField(outputField) {}
    Mapper(std::string fieldId, std::string value) : Mapper(fieldId, value, fieldId) {}
    // long value
    Mapper(std::string fieldId, long value, std::string outputField)
        : fieldId(fieldId), value(std::to_string(value)), outputField(outputField) {}
    Mapper(std::string fieldId, long value) : Mapper(fieldId, value, fieldId) {}
    // field Value
    Mapper(std::string fieldId, Field &value, std::string outputField)
        : fieldId(fieldId), value("record." + value.name), outputField(outputField) {}
    Mapper(std::string fieldId, Field &value) : Mapper(fieldId, value, fieldId) {}

    std::string to_string() { return "Map Field: " + fieldId + "  on " + value + " with " + outputField; }

    virtual Event convert(Event record) = 0;

protected:
    std::string fieldId;
    std::string value;
    std::string outputField;
};

// subtract fields and adds a filed
class Add : public Mapper {
public:
    Add(std::string fieldId, std::string value) : Mapper(fieldId, value) {}
    Add(std::string fieldId, std::string value, std::string outputField) : Mapper(fieldId, value, outputField) {}
    Add(std::string fieldId, long value) : Mapper(fieldId, value) {}
    Add(std::string fieldId, long value, std::string outputField) : Mapper(fieldId, value, outputField) {}
    Add(std::string fieldId, Field &value) : Mapper(fieldId, value) {}
    Add(std::string fieldId, Field &value, std::string outputField) : Mapper(fieldId, value, outputField) {}
};

//  a value from a field or subtract one field from another
class Subtract : public Mapper {
public:
    Subtract(std::string fieldId, std::string value) : Mapper(fieldId, value) {}
    Subtract(std::string fieldId, std::string value, std::string outputField) : Mapper(fieldId, value, outputField) {}
    Subtract(std::string fieldId, long value) : Mapper(fieldId, value) {}
    Subtract(std::string fieldId, long value, std::string outputField) : Mapper(fieldId, value, outputField) {}
    Subtract(std::string fieldId, Field &value) : Mapper(fieldId, value) {}
    Subtract(std::string fieldId, Field &value, std::string outputField) : Mapper(fieldId, value, outputField) {}
};

// transform some fields to one filed
class Transform : public Mapper {
private:
    std::vector<size_t> subtractFieldIndex;
    std::vector<Field> addFields;
    std::vector<std::string> values;

public:
    Transform(std::vector<size_t> subtractFieldIndex, std::vector<Field> addFields, std::vector<std::string> values) : subtractFieldIndex(subtractFieldIndex), addFields(addFields), values(values) {}
    Event convert(Event record);
};

class MapOperator : public Operator {
public:
    MapOperator(Mapper &mapper, Operator *input);
    ~MapOperator();

    std::string to_string();
    // Mapper* get_mapper();
    Event process_data(Event record);

private:
    Mapper &mapper;
    Operator *input;
};