#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e7+10;
int n,A,B,C;
int a[maxn];
double f[maxn];
void init()
{
	scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
	for (int i = 2; i <= n; i++)
		a[i] = ((long long) a[i - 1] * A + B) % 100000001;
	for (int i = 1; i <= n; i++)
		a[i] = a[i] % C + 1;
}
int main()
{
	init();
	a[n+1]=a[1];
	for(int i=2;i<=n+1;i++)
		f[i]=f[i-1]+1.0/(1.0*a[i]*a[i-1])*min(a[i],a[i-1]);
	printf("%.3f",f[n+1]);
}
