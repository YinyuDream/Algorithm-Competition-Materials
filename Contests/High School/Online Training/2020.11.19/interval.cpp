#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
int n,l,r,ans,cnt;
int a[maxn],f[maxn][20],g[maxn][20],pos[maxn];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
void pre()
{
	for(int i=1;i<=n;i++)
		f[i][0]=g[i][0]=a[i];
	for(int i=1;i<=19;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			f[j][i]=gcd(f[j][i-1],f[j+(1<<(i-1))][i-1]),
			g[j][i]=min(g[j][i-1],g[j+(1<<(i-1))][i-1]);
}
bool query(int l,int r)
{
	int t=log2(r-l+1);
	return gcd(f[l][t],f[r-(1<<t)+1][t])==min(g[l][t],g[r-(1<<t)+1][t]);
}
bool check(int x)
{
	int num=0;
	for(int i=1;i+x-1<=n;i++)
		if(query(i,i+x-1))
			num++;
	return num>0;
}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	pre();
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	for(int i=1;i+ans-1<=n;i++)
		if(query(i,i+ans-1))
			pos[++cnt]=i;
	printf("%d %d\n",cnt,ans-1);
	for(int i=1;i<=cnt;i++)
		printf("%d ",pos[i]);
	return 0;
}
