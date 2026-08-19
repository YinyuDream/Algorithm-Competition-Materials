#include<cstdio>
using namespace std;
int n,top,K;
int mapp[(1<<9)-1],cnt[(1<<9)-1];
long long ans,f[10][(1<<9)-1][100];
int find(int x)
{
	int ans=0;
	while(x){
		if(x&1)
		ans++;
		x>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=0;i<(1<<n);i++)
		if((i&(i<<1))==0)
			mapp[++top]=i,cnt[top]=find(i);
	f[1][0][0]=1;
	for(int i=1;i<=top;i++){
		f[1][mapp[i]][cnt[i]]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=top;j++)
		{
			for(int k=1;k<=top;k++)
			{
				if(!(mapp[j]&mapp[k])&&!(mapp[j]&(mapp[k]<<1))&&!(mapp[j]&(mapp[k]>>1)))
				{	
					for(int l=0;l<=K;l++)
					{
						if(l-cnt[j]>=0)
						{
							f[i][mapp[j]][l]+=f[i-1][mapp[k]][l-cnt[j]];
						}
					}
				}
			}	
		} 
	}
	for(int i=1;i<=top;i++)
	ans+=f[n][mapp[i]][K];
	printf("%lld",ans);
	return 0;
}
