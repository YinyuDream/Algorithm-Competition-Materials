#include "WindowOperator.h"

WindowOperator::WindowOperator(Window &window, Operator *input)
    : window(window), input(input) {
    leftChild = NULL;
    rightChild = NULL;
    input->parent = this;
    name = "Window";
}

WindowOperator::~WindowOperator() { delete input; }

std::string WindowOperator::to_string() { return "Window"; }

Event WindowOperator::process_data(Event record) {
    return Event(EventType::NOVALUE);
}