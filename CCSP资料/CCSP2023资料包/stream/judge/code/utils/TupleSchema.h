#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

struct DataType {
    enum Type { Boolean,
                Char,
                String,
                Int,
                Long,
                Double,
                ULL } t_;

    DataType(Type t) : t_(t) {}

    operator Type() const { return t_; }

    size_t defaultSize() {
        switch (t_) {
        case DataType::String:
            return 255;
        default:
            return 1;
        }
    }

    const std::string cType() const {
        switch (t_) {
        case DataType::Boolean:
            return "bool";
        case DataType::Char:
            return "char";
        case DataType::String:
            return "char";
        case DataType::Int:
            return "int";
        case DataType::Long:
            return "long";
        case DataType::Double:
            return "double";
        case DataType::ULL:
            return "unsigned long long";
        default:
            throw std::invalid_argument("data type not supported");
        }
    }

    const std::string keyType() const {
        switch (t_) {
        case DataType::Boolean:
            return "bool";
        case DataType::Char:
        case DataType::String:
            return "std::string";
        case DataType::Int:
            return "int";
        case DataType::Long:
            return "long";
        case DataType::Double:
            return "double";
        case DataType::ULL:
            return "unsigned long long";
        default:
            throw std::invalid_argument("data type not supported");
        }
    }
};

class Field {
public:
    std::string name;
    DataType dataType;
    std::size_t size;

    Field(std::string fname, DataType type) : name(fname), dataType(type) {}
    Field(std::string fname, DataType type, std::size_t dataSize) : name(fname), dataType(type), size(dataSize) {}
};

/*
 * This class is used for defining the schema of a stream.
 * */
class TupleSchema {
public:
    std::vector<Field> fields;

    TupleSchema() {}

    static TupleSchema create() { return TupleSchema(); }

    TupleSchema &addFixSizeField(std::string pNname, DataType dataType) {
        fields.push_back(Field(pNname, dataType, dataType.defaultSize()));
        return *this;
    }

    Field &get(std::string pName) {
        for (auto &f : fields) {
            if (f.name == pName)
                return f;
        }
        throw std::invalid_argument("field " + pName + " does not exist");
    }

    void parse(TupleSchema &tuple, std::string &line) {
    }
};
