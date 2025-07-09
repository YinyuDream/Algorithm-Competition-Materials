#include <iostream>
#include <string>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<int> num(10, 0);

    for (int i = m; i <= n; i++) {
        std::string l = std::to_string(i);
        for (char j : l) {
            num[j - '0']++;
        }
    }

    for (int i : num) {
        std::cout << i << " ";
    }

    return 0;
}
