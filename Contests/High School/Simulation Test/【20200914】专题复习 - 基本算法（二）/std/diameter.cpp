#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef int arr32[1000010];

arr32 c, nxt, g;
int x, y, n, k, ap, val, limit;

void link(int x, int y)  {
	c[++ap] = y, nxt[ap] = g[x], g[x] = ap;
	c[++ap] = x, nxt[ap] = g[y], g[y] = ap;
}
int dfs(int z, int ft)  {
	int cnt = 0, rm = limit, lm = 0; 
	for (int x = g[z]; x; x = nxt[x])
		if (c[x] != ft)  {
			int p = dfs(c[x], z) + 1;
			if (p > limit)  ++val;
			else  if (p > limit / 2)  ++cnt, rm = min(rm, p);
			else  lm = max(lm, p);
		}
	if (cnt != 0)  {
		val += cnt;
		if (rm + lm <= limit)  return --val, rm;
		else  return lm;
	}
	return lm;
}
int main()  {
	freopen("diameter.in", "r", stdin);
	freopen("diameter.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; ++i)  {
		scanf("%d %d", &x, &y);
		link(x, y);
	}
	if (k >= n - 1)  printf("0"), exit(0);
	int l = 1, r = n - 1, j, an;
	for (; j = (l + r) >> 1, l <= r; )  {
	  limit = j, val = 0;
		dfs(1, 0);
		if (val > k)  l = j + 1;
		else  an = j, r = j - 1;
	}
	printf("%d", an);
}
