#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
using namespace std;
int n, m;
int fa[10010];
int find(int a)
{
	if (fa[a] == a)return a;
	fa[a] = find(fa[a]);
	return fa[a];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int z, x, y;
		scanf("%d%d%d", &z, &x, &y);
		int fx = find(x), fy = find(y);
		if (z == 1)
		{
			fa[fx] = fy;
		}
		else
		{
			if (fx == fy)
			{
				printf("Y\n");
			}
			else
			{
				printf("N\n");
			}
		}
	}
	return 0;
}