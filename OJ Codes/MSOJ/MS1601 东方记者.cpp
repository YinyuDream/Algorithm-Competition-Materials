#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n,ans;
ll d,f[maxn][maxn];
struct node{
	ll x,y;
}p[maxn];
ll dis(node a,node b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	//freopen("news.in","r",stdin);
	//freopen("news.out","w",stdout);
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	scanf("%lld",&d);
	for(int i=1;i<=n;i++){
		f[i][1]=dis(p[0],p[i]);
		for(int j=2;j<=i;j++)
			for(int k=j-1;k<i;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+dis(p[k],p[i]));
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(f[i][j]+dis(p[i],p[0])<=d)	
				ans=max(ans,j);
	printf("%d",ans);
}