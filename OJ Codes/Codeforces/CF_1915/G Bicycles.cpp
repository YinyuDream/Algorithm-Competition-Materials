#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int T, n, m, k;
ll ans;
struct node
{
	int to, next, wt;
	node()
	{
		to = next = wt = 0;
	}
} edge[maxn * 2];
struct point
{
	int id, slow;
	ll dis;
	point(int _id, ll _dis, int _slow)
	{
		id = _id;
		dis = _dis;
		slow = _slow;
	}
};
int head[maxn], p[maxn], book[maxn][maxn];
ll dis[maxn][maxn];
bool operator<(point a, point b)
{
	return a.dis > b.dis;
}
void add(int u, int v, int w)
{
	edge[++k].to = v;
	edge[k].next = head[u];
	edge[k].wt = w;
	head[u] = k;
}
priority_queue<point> q;
void init()
{
	k = 0;
	ans = 0x3f3f3f3f3f3f3f3fll;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		head[i] = 0;
		edge[i * 2 - 1] = edge[i * 2] = node();
	}
	for (int i = 1, u, v, w; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
}
ll ex_dijkstra()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < maxn; j++)
		{
			dis[i][j] = 0x3f3f3f3f3f3f3f3fll;
			book[i][j] = 0;
		}
	dis[1][p[1]] = 0;
	q.push(point(1, 0, p[1]));
	while (q.size())
	{
		point u = q.top();
		q.pop();
		if (book[u.id][u.slow])
		{
			continue;
		}
		int new_slow = min(u.slow, p[u.id]);
		book[u.id][u.slow] = 1;
		for (int i = head[u.id]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!book[v][new_slow] && dis[v][new_slow] > dis[u.id][u.slow] + 1ll * edge[i].wt * new_slow)
			{
				dis[v][new_slow] = dis[u.id][u.slow] + 1ll * edge[i].wt * new_slow;
				q.push(point(v, dis[v][new_slow], new_slow));
			}
		}
	}
	for (int i = 1; i < maxn; i++)
		ans = min(ans, dis[n][i]);
	return ans;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%lld\n", ex_dijkstra());
	}
	return 0;
}