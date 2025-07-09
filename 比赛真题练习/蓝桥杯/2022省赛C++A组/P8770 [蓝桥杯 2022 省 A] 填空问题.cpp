#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "443",
        "VLVV",
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}