#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10,MOD=1e9+9;
int n,t,a[maxn],b[maxn];
int f[maxn][maxn];
int main()
{
	freopen("pie.in","r",stdin);
	freopen("pie.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int k=1;k<=n;k++)
		for(int i=0;i<=t;i++)
			{
				if(a[k]<b[k]);
				else;
			}
	return 0;
 } 
