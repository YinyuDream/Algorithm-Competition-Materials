#include<cstdio>
using namespace std;
const int N=12,mod=1e8;
int n,m,ans;
int mapp[N],dp[N][1<<N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int t;
			scanf("%d",&t);
			if(t==0){
				mapp[i]+=(1<<(j-1));
			}
		}
	for(int i=0;i<(1<<m);i++)
		if(!(i&(i<<1))&&!(mapp[1]&i))
			dp[1][i]++;
	for(int i=2;i<=n;i++)
		for(int j=0;j<(1<<m);j++)
			if(!(j&(j<<1))&&!(mapp[i]&j))
				for(int k=0;k<(1<<m);k++)
					if(!(k&(k<<1))&&!(mapp[i-1]&k)&&!(k&j))
						dp[i][j]+=dp[i-1][k],
						dp[i][j]%=mod;
	for(int i=0;i<(1<<m);i++)
		if(!(i&(i<<1)))
			ans+=dp[n][i],
			ans%=mod;
	printf("%d\n",ans);
	return 0;
}
