#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e3+10;
int n,ans,cnt,p;
int a[maxn],f[maxn],g[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=g[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=1;g[i]=1;
		for(int j=1;j<i;j++)
			if(a[j]>a[i])
			{
				if(f[i]<f[j]+1)
				{
					f[i]=f[j]+1;
					g[i]=g[j];
				}
				else if(f[i]==f[j]+1)
				{
					g[i]+=g[j];
				}
			}
	}
	for(int i=1;i<=n;i++)
		if(f[p]<f[i])
			p=i,cnt=g[i];
		else if(f[p]==f[i])
			cnt+=g[i];
	printf("%d %d",f[p],cnt);
	return 0;
}
