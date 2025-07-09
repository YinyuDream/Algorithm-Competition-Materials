#include <iomanip>
#include <iostream>
#include <thread>

#include "../operator/FilterOperator.h"
#include "../operator/SinkOperator.h"
#include "../operator/SourceOperator.h"
#include "../runtime/ChannelRuntime.h"
#include "Query.h"

Query::Query() {}
Query::~Query() {}

/* Input Operators */
Query Query::source(TupleSchema &inputSchema, std::vector<std::string> paths) {
    Query *q = new Query();
    q->current = new SourceOperator(InputType::Memory, inputSchema, paths);
    q->root = q->current;
    return *q;
}

void Query::execute() {
}

/* transform operators */
Query &Query::filter(Predicate &predicate) {
    Operator *newOp = new FilterOperator(predicate, current);
    if (current)
        newOp->rightChild = current;
    root = newOp;
    current = newOp;
    return *this;
}

Query &Query::map(Mapper &mapper) {
    Operator *newOp = new MapOperator(mapper, current);
    if (current)
        newOp->rightChild = current;
    root = newOp;
    current = newOp;
    return *this;
}

Query &Query::window(Window &window_) {
    Operator *newOp = new WindowOperator(window_, current);
    if (current)
        newOp->rightChild = current;
    root = newOp;
    current = newOp;
    return *this;
}

/* Output Operators */
Query &Query::sink(OutputType outputType) {
    Operator *newOp = new SinkOperator(outputType);
    if (current)
        newOp->rightChild = current;
    root = newOp;
    current = newOp;
    return *this;
}

void Query::printQueryPlan(Operator *p, int indent) {
    // Taken from https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
    if (p != NULL) {
        if (p->rightChild) {
            printQueryPlan(p->rightChild, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->rightChild)
            std::cout << " /\n"
                      << std::setw(indent) << ' ';
        std::cout << p->to_string() << "\n ";
        if (p->leftChild) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            printQueryPlan(p->leftChild, indent + 4);
        }
    }
}

void Query::printQueryPlan(Query query) {
    std::cout << "Query Plan " << std::string(69, '-') << std::endl;

    if (query.root == NULL) {
        printf("No root node; cant print queryplan\n");
    } else {
        printQueryPlan(query.current, 0);
        printf("\n");
    }
}