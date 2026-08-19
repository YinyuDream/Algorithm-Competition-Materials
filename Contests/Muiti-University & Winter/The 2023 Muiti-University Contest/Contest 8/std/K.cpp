#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    for (; T; T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        std::vector<int> l(n, n), r(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                l[i] = std::min(l[i], (a[i][j] - 1) / m);
                r[i] = std::max(r[i], (a[i][j] - 1) / m);
            }
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] != r[i]) { k = 3; break; }
            if (l[i] != i) { k++; }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j - 1] > a[i][j]) { k = 3; }
            }
        }
        if (k == 2) {
            puts("FOX");
        } else if (n == 2 && m == 2) {
            for (int i = 0; i < 16; i++) {
                std::swap(a[0][0], a[1][0]); std::swap(a[0][1], a[1][1]);
                if (a[0][0] == 1 && a[0][1] == 2 && a[1][0] == 3 && a[1][1] == 4) { puts("FOX"); break; }
                std::swap(a[0][0], a[0][1]); std::swap(a[1][0], a[1][1]);
                if (a[0][0] == 1 && a[0][1] == 2 && a[1][0] == 3 && a[1][1] == 4) { puts("CAT"); break; }
                if (i == 15) { puts("NSFW"); }
            }
        } else if (m == 2) {
            bool gg = false, x = false, y = false;
            for (int i = 0; i < n; i++) {
                if (std::abs(a[i][0] - a[i][1]) != 1) { gg = true; break; }
                x |= a[i][0] < a[i][1]; y |= a[i][0] > a[i][1];
            }
            if (gg || (x && y)) { puts("NSFW"); continue; }
            int inv = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (a[j][0] > a[i][0]) { inv ^= 1; }
                }
            }
            puts((inv ^ y) ? "FOX" : "NSFW");
        } else if (n == 2) {
            bool gg = false, x = false, y = false;
            for (int i = 0; i < m; i++) {
                if (std::abs(a[0][i] - a[1][i]) != m) { gg = true; break; }
                x |= a[0][i] < a[1][i]; y |= a[0][i] > a[1][i];
            }
            if (gg || (x && y)) { puts("NSFW"); continue; }
            int inv = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < i; j++) {
                    if (a[0][j] > a[0][i]) { inv ^= 1; }
                }
            }
            puts((inv ^ y) ? "NSFW" : "CAT");
        } else {
            puts("NSFW");
        }
    }
    return 0;
}