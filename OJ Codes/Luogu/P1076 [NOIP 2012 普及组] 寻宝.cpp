#include<cstdio>
using namespace std;
const int maxn=1e4+10,maxm=1e2+10,p=20123;
int n,m,ans,now;
int is[maxn][maxm],b[maxn][maxm],sum[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d%d",&is[i][j],&b[i][j]),
			sum[i]+=is[i][j];
	scanf("%d",&now),now++;
	for(int i=1;i<=n;i++)
	{
		int cnt=is[i][now],step=b[i][now];
		ans=(ans+step)%p;
		if(step%sum[i]!=0)
		step%=sum[i];
		else
		step=sum[i];
		while(cnt<step)
		{
			now++;
			if(now>m)now-=m;
			cnt+=is[i][now];
		}
	}
	printf("%d",ans);
	return 0;
}
