#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10,inf=0x3f3f3f3f;
int n,ans=inf;
int a[maxn],f[maxn],g[maxn];
int main(){
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	scanf("%d",&n);
	f[1]=g[n]=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(a[j]<a[i])
				f[i]=min(f[i],f[j]+i-j-1);
		if(f[i]==inf)f[i]=i-1;
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=n;j>i;j--)
			if(a[j]<a[i])
				g[i]=min(g[i],g[j]+j-i-1);
		if(g[i]==inf)g[i]=n-i;
	}
				
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]+g[i]);
	printf("%d",ans);
	return 0;
}
