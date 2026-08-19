#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#define MAXN 1010  
#define INF 0x3f3f3f3f  
#define eps 1e-8  
using namespace std;  
int N;  
double Map[MAXN][MAXN];  
struct Node  
{  
    double x, y, h;  
};  
Node num[MAXN];  
double cost[MAXN][MAXN], len[MAXN][MAXN];  
double dis(Node a, Node b)  
{  
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));  
}  
double Max;  
void getMap()//求出cost 和 len  
{  
    Max = 0;  
    for(int i = 0; i < N; i++)  
    {  
        for(int j = i+1; j < N; j++)  
        {  
            cost[i][j] = cost[j][i] = fabs(num[i].h - num[j].h);  
            len[i][j] = len[j][i] = dis(num[i], num[j]);  
            Max = max(Max, cost[i][j] / len[i][j]);  
        }  
    }  
}  
double low[MAXN];  
bool vis[MAXN];  
double prime()//求最小生成树  
{  
    for(int i = 0; i < N; i++)  
    {  
        vis[i] = false;  
        low[i] = Map[0][i];  
    }  
    vis[0] = true;  
    double ans = 0;  
    for(int i = 1; i < N; i++)  
    {  
        double Min = INF;  
        int next = 0;  
        for(int j = 0; j < N; j++)  
        {  
            if(!vis[j] && Min > low[j])  
            {  
                next = j;  
                Min = low[j];  
            }  
        }  
        if(Min == INF) break;  
        vis[next] = true;  
        ans += Min;  
        for(int j = 0; j < N; j++)  
        {  
            if(!vis[j])  
                low[j] = min(low[j], Map[next][j]);  
        }  
    }  
    return ans;  
}  
bool judge(double o)  
{  
    for(int i = 0; i < N; i++)  
    {  
        for(int j = i+1; j < N; j++)//重新计算Map值  
            Map[i][j] = Map[j][i] = cost[i][j] - o * len[i][j];  
    }  
    return prime() >= 0;//判断构造最小生成树的 Map值总和是否大于或等于0  
}  
int main()  
{  
    while(scanf("%d", &N), N)  
    {  
        for(int i = 0; i < N; i++)  
            scanf("%lf%lf%lf", &num[i].x, &num[i].y, &num[i].h);  
        getMap();  
        double l = 0, r = Max, mid;  
        while(r - l >= eps)  
        {  
            mid = (l + r) / 2;  
            if(judge(mid))  
                l = mid;  
            else  
                r = mid;  
        }  
        printf("%.3lf\n", l);  
    }  
    return 0;  
}