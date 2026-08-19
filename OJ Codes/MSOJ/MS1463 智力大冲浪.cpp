#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 510;
int m,n,ans;
struct node {
	int t, money;
}a[maxn];
int t[maxn];
bool cmp(node x, node y)
{
	return x.money > y.money;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].money);
	sort(a+1,a+n+1,cmp);
	ans = m;
	for (int i = 1; i <= n; i++)
	{
		while (t[a[i].t]&&a[i].t>0)
		{
			a[i].t--;
		}
		if (a[i].t == 0)ans -= a[i].money;
		else t[a[i].t] = 1;
	}
	printf("%d", ans);
	return 0;
}