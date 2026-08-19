#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n;
ll f[maxn][maxn],g[maxn][maxn],ans=-0x3f3f3f3f;
int a[maxn],opt[maxn],edge[maxn],cnt;
ll query(int l,int m,int r,int o)
{
	int t1=f[l][m]*g[m+1][r],
		t2=f[l][m]*f[m+1][r],
		t3=g[l][m]*f[m+1][r],
		t4=g[l][m]*g[m+1][r];
	if(o==0)
		return min(t1,min(t2,min(t3,t4)));
	else
		return max(t1,max(t2,max(t3,t4)));
}
int main(){
	memset(g,0x3f,sizeof g);
	memset(f,-0x3f,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char o;int x;
		scanf(" %c%d",&o,&x);
		a[i]=x;opt[i]=o=='t'?0:1;
		a[i+n]=a[i];
		opt[i+n]=opt[i];
	}
	for(int i=1;i<=n*2;i++)
		g[i][i]=f[i][i]=a[i];
	for(int len=2;len<=n*2;len++)
		for(int l=1;l+len-1<=n*2;l++)
			for(int k=l;k<l+len-1;k++)
				if(opt[k+1]==0){
					f[l][l+len-1]=max(f[l][l+len-1],f[l][k]+f[k+1][l+len-1]);
					g[l][l+len-1]=min(g[l][l+len-1],g[l][k]+g[k+1][l+len-1]);
				}else{
					f[l][l+len-1]=max(f[l][l+len-1],query(l,k,l+len-1,1));
					g[l][l+len-1]=min(g[l][l+len-1],query(l,k,l+len-1,0));
				}
	for(int i=1;i<=n;i++)
		if(ans<f[i][i+n-1])
			ans=f[i][i+n-1],edge[cnt=1]=i;
		else if(ans==f[i][i+n-1])
			edge[++cnt]=i;
	printf("%lld\n",ans);
	for(int i=1;i<=cnt;i++)
		printf("%d ",edge[i]);
	return 0;
}
