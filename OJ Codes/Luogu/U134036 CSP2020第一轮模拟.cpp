#include <string>
#include <iostream>
using namespace std;

int main() {
    string ans =
        "ABCBACABCBDBBDD"
        "FTTTBD"
        "FTTTAA"
        "FFTTCC"
        "CBDAC"
        "CBDCB";
    int no;
    cin >> no;
    cout << ans[no - 1];
    return 0;
}