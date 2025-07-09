#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);
    // skip 4 lines;
    inf.readLine(), inf.readLine(), inf.readLine(), inf.readLine();
    auto oMag = ans.readLine();
    ans.reset();
    while (!ouf.eof()) {
        auto oufLine = ouf.readLine();
        if (oufLine == "") break;
        auto ansLine = ans.readLine();
        if (ansLine != oufLine) quitf(_wa, "Wrong answer in stdout.");
    }
    while (!inf.eof()) {
        auto filename = inf.readLine();
        if (filename == "") break;
        InStream of;
        of.init(filename.c_str(),_output);
        while (!of.eof()) {
            auto oufLine = of.readLine();
            if (oufLine == "") break;
            auto ansLine = ans.readLine();
            if (ansLine != oufLine) quitf(_wa, "Wrong answer in %s.", filename.c_str());
        }
        auto ansLine = ans.readLine();
        if(ansLine != oMag) quitf(_wa, "Wrong answer in %s.", filename.c_str());
    }
    quitf(_ok, "Correct.");
    return 0;
}
