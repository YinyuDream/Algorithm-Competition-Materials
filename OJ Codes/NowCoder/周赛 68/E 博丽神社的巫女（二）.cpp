#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    const int target = 100000;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    vector<vector<int>> from(n + 1, vector<int>(target + 1, -1));  // 记录从哪个值转移过来

    dp[0][0] = true; // 初始状态，前0个数，和为0是可行的

    // 遍历每个元素
    for (int i = 1; i <= n; i++) {
        // 遍历目标和
        for (int j = 0; j <= target; j++) {
            // 对每个数a[i]进行不同次的右移（除以2操作）
            for (int k = 0; k <= 20; k++) {
                int val = a[i] >> k;  // 计算a[i]右移k位的值
                if (j - val >= 0 && dp[i-1][j - val]) {
                    dp[i][j] = true;
                    from[i][j] = k;  // 记录通过右移k位得到这个值
                    break;  // 一旦找到一个可行的操作，跳出循环，避免重复更新
                }
            }
        }
    }

    // 如果 dp[n][target] 为 true，则输出 "Yes"，并输出每个数的操作次数
    if (dp[n][target]) {
        // 输出操作次数
        vector<int> operations;
        int curr_sum = target;

        // 回溯每个数的操作次数
        for (int i = n; i > 0; i--) {
            int k = from[i][curr_sum];
            if (k != -1) {
                operations.push_back(k);
                curr_sum -= (a[i] >> k);
            }
        }

        // 打印出操作次数的顺序
        reverse(operations.begin(), operations.end());
        for (int ops : operations) {
            cout << ops << " ";
        }
        cout << endl;
    } else {
        cout << "-1\n";
    }

    return 0;
}