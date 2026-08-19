#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,ans;
int x[maxn],y[maxn];
double s[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
	{
		int cnt=0,maxx=1;
		for(int j=1;j<=n;j++)
			if(j!=i)
				s[++cnt]=(1.0*y[i]-y[j])/(1.0*x[i]-x[j]);
		sort(s+1,s+cnt+1);
		for(int j=1;j<cnt;j++)
		{
			if(s[j]==s[j+1])maxx++;
			else maxx=1;
			ans=max(ans,maxx);
		}	
	}
	printf("%d",ans+1);
	return 0;
}