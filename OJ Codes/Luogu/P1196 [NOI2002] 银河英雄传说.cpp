#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 3e4 + 10;
int t;
struct node
{
	int fa, dis, num;
}a[maxn];
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
int find(int x)
{
	if (a[x].fa == x)return x;
	int ac = find(a[x].fa);
	a[x].dis += a[a[x].fa].dis;
	return a[x].fa= ac;
}
int main()
{
	t = read();
	for (int i = 1; i <= 30000; i++)
	{
		a[i].fa = i;
		a[i].dis = 0;
		a[i].num = 1;
	}
	for (int k = 1; k <= t; k++)
	{
		char ch;
		scanf(" %c", &ch);
		int i = read(), j = read();
		int fi = find(i), fj = find(j);
		if (ch == 'C')
		{
			if (fi != fj)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", abs(a[i].dis - a[j].dis) - 1);
			}
		}
		if (ch == 'M')
		{
			a[fi].dis += a[fj].num;
			a[fi].fa = a[fj].fa;
			a[fj].num += a[fi].num;
			a[fi].num = 0;

		}
	}
	return 0;
}