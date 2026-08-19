#pragma once

#include "../operator/FilterOperator.h"
#include "../operator/MapOperator.h"
#include "../operator/Operator.h"
#include "../operator/WindowOperator.h"
#include "../utils/Event.h"
#include "../utils/SystemConf.h"

#include <string>
#include <vector>

class Query {
private:
    static void printQueryPlan(Operator *curr, int depth);

public:
    Operator *root;
    Operator *current;
    Query();
    ~Query();

    // construct new Query with SourceOperator
    static Query source(TupleSchema &inputSchema, std::vector<std::string> paths);

    // operators
    Query &filter(Predicate &predicate);
    Query &filter(Predicate &&predicate) { return filter(predicate); }
    Query &filter(Predicate *predicate) { return filter(*predicate); }

    Query &map(Mapper &mapper);
    Query &map(Mapper &&mapper) { return map(mapper); }
    Query &map(Mapper *mapper) { return map(*mapper); }

    Query &window(Window &window_);
    Query &window(Window *window_) { return window(*window_); };
    Query &window(Window &&window_) { return window(&window_); };

    // output operators
    Query &sink(OutputType outputType);

    // execute those operators
    void execute();

    // helper
    static void printQueryPlan(Query query);
};