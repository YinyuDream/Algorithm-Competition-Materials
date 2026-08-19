#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (s[0] - '0') * 10 + (s[1] - '0');
        vector<int> cube1, cube2;
        bool yes = false;

        if (n >= 1 && n <= 8) {
            yes = true;
            if (n == 1) {
                cube1 = {0,0,0,0,0,0};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 2) {
                cube1 = {1,1,1,1,1,1};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 3) {
                cube1 = {1,2,1,2,1,2};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 4) {
                cube1 = {1,2,3,1,2,3};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 5) {
                cube1 = {1,2,3,4,1,2};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 6) {
                cube1 = {1,2,3,4,5,1};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 7) {
                cube1 = {1,2,3,4,5,6};
                cube2 = {0,0,0,0,0,0};
            } else if (n == 8) {
                cube1 = {0,1,2,3,4,6};
                cube2 = {0,5,7,0,0,0};
            }
        } else if (n == 11) {
            yes = true;
            cube1 = {0,4,5,6,7,8};
            cube2 = {0,1,2,3,0,0};
        } else if (n == 22) {
            yes = true;
            cube1 = {0,1,2,3,4,6};
            cube2 = {0,1,5,7,8,8};
        } else if (n == 33) {
            yes = true;
            cube1 = {0,1,2,3,6,8};
            cube2 = {0,1,2,4,5,7};
        } else {
            yes = false;
        }

        if (yes) {
            cout << "Yes\n";
            vector<int> ans;
            ans.insert(ans.end(), cube1.begin(), cube1.end());
            ans.insert(ans.end(), cube2.begin(), cube2.end());
            for (int i = 0; i < 12; ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        } else {
            cout << "No\n";
        }
    }
    return 0;
}