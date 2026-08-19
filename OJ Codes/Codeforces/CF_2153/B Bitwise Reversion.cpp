#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        bool valid = true;
        for (int i = 0; i < 32; i++) {
            int xi = (x >> i) & 1;
            int yi = (y >> i) & 1;
            int zi = (z >> i) & 1;
            if (!((xi == 0 && yi == 0 && zi == 0) ||
                (xi == 0 && yi == 0 && zi == 1) ||
                (xi == 0 && yi == 1 && zi == 0) ||
                (xi == 1 && yi == 0 && zi == 0) ||
                (xi == 1 && yi == 1 && zi == 1))) {
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}