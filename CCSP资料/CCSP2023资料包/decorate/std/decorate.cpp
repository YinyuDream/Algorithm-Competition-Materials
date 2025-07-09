#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 10010;
const int M = 10010;
const long long Mod = 1000000007;
int n, m, p, q;
vector<int> compose[M];
int cost[M];
int d[M];
int need[M];
int tmp_need[M];
int trade_s[10], trade_r[10];
vector<int> pack[10];
int pack_cost[10];
vector<int> order;
int ans = -1;
int rz[11], z = 0;

void get_order() {
    queue<int> s;
    for (int i = 0; i <= m; i++)
        if (d[i] == 0)
            s.push(i);
    while(!s.empty()) {
        int u = s.front();
        order.push_back(u);
        s.pop();
        for (vector<int>::iterator it = compose[u].begin(); it != compose[u].end(); it++) {
            d[*it]--;
            if (d[*it] == 0)
                s.push(*it);
        }
    }
}

int get_cost() {
    memset(tmp_need, 0, sizeof(tmp_need));
    tmp_need[0] = 1;
    int total_cost = 0;
    for (vector<int>::iterator u = order.begin(); u != order.end(); u++)
    {   
        tmp_need[*u] += need[*u];
        if (tmp_need[*u] <= 0)
            continue;
        total_cost += tmp_need[*u] * cost[*u];
        for (vector<int>::iterator it = compose[*u].begin(); it != compose[*u].end(); it++) {
            tmp_need[*it] += tmp_need[*u];
        }
    }
    // cerr << total_cost << endl;
    return total_cost;
}
void dfs(int trade_index, int pack_index, int dep) {
    if (trade_index < p) {
        rz[++z] = 0;
        dfs(trade_index+1, pack_index, dep);
        rz[z] = 1;
        need[trade_r[trade_index]] --;
        need[trade_s[trade_index]] ++;
        
        dfs(trade_index+1, pack_index, dep);
        z--;
        need[trade_r[trade_index]] ++;
        need[trade_s[trade_index]] --;
    }
    else if(pack_index < q) {
        rz[++z] = 0;

        dfs(trade_index, pack_index+1, dep);
        rz[z] = 1;

        for (vector<int>::iterator u = pack[pack_index].begin(); u != pack[pack_index].end(); u++)
            need[*u] --;
        // cerr <<  << endl;
        // cerr << pack_index << " " << pack_cost[pack_index] << endl;
        dfs(trade_index, pack_index+1, dep + pack_cost[pack_index]);
        z--;
        for (vector<int>::iterator u = pack[pack_index].begin(); u != pack[pack_index].end(); u++)
            need[*u] ++;
    }
    else 
    {
        int result = dep + get_cost();
        // printf("\n%d ", result);

        if (ans == -1 || result < ans) {
            ans = result;
            // printf("\n%d ", result);
            // for(int i = 1; i <= p+q; i++)
            //     printf("%d ", rz[i]);
        }
    }
    return ;
}
int main() {
    scanf("%d %d %d %d", &n, &m, &p, &q);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        compose[0].push_back(tmp);
        d[tmp] ++;
    }
    for (int i = 1; i <= m; i++) {
        int c;
        scanf("%d", &c);
        if (c == 0) 
            scanf("%d", &cost[i]);
        else {
            for (int j = 0; j < c; j++) {
                int tmp;
                scanf("%d", &tmp);
                d[tmp] ++;
                compose[i].push_back(tmp);
            }
        }
    }
    get_order();
    // for (int i = 0; i < m; i++)
    //     printf("%d ", order[i]);
    // cout << d[4] << endl;
    for (int i = 0; i < p; i++)
        scanf("%d %d", &trade_s[i], &trade_r[i]);
    for (int i = 0; i < q; i++)
    {
        int c;
        scanf("%d %d", &c, &pack_cost[i]);
        for (int j = 0; j < c; j++) {
                int tmp;
                scanf("%d", &tmp);
                pack[i].push_back(tmp);
            }
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
}