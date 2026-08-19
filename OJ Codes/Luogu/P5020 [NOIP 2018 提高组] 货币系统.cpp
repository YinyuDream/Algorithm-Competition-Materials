#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e4+10;
int a[maxn],f[maxn],ans,n,T;
int main()
{
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		memset(f,0,sizeof f);
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		f[0]=1;
		for(int i=0;i<=a[n];i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i+a[j]>a[n])break;
				f[i+a[j]]=1; 
			}
		}
		for(int i=1;i<=n;i++)
			if(f[i]==0)
				ans++;
		printf("%d\n",ans);
	}
}