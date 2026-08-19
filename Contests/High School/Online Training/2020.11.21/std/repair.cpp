#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7,N=22;
int n,K;
int a[N],w[N],cnt[1<<N],MAX[1<<N],f[1<<N][2],g[1<<N][2];

int main(void)
{
	freopen("repair.in","r",stdin);
	freopen("repair.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(register int i=0;i<n;++i)
		scanf("%d",a+i);
	for(register int i=0;i<n;++i)
		f[1<<i][0]=1;
	for(register int i=0;i<1<<n;++i)
		for(register int j=0;j<n;++j)
			if(i&1<<j)
			{
				MAX[i]=max(MAX[i],a[j]);
				++cnt[i];
			}
	for(register int i=2;i<=n;++i)
		w[i]=((w[i-1]<<1)+1)%mod;
	for(register int i=1;i<1<<n;++i)
		for(register int j=0;j<n;++j)
			if(!(i&1<<j))
				for(register int k=0;k<2;++k)
					if(MAX[i]+k==a[j])
					{
						f[i|1<<j][1]=(f[i|1<<j][1]+f[i][k])%mod;
						g[i|1<<j][1]=(g[i|1<<j][1]+g[i][k]+f[i][k]*(1ll*K*(a[j]+1)%mod+w[cnt[i]]))%mod;
					}
					else if(MAX[i]+k>a[j])
					{
						f[i|1<<j][k]=(f[i|1<<j][k]+f[i][k])%mod;
						g[i|1<<j][k]=(g[i|1<<j][k]+g[i][k]+f[i][k]*(1ll*K*(MAX[i]+k)%mod+w[cnt[i]]))%mod;
					}
					else
					{
						f[i|1<<j][0]=(f[i|1<<j][0]+f[i][k])%mod;
						g[i|1<<j][0]=(g[i|1<<j][0]+g[i][k]+f[i][k]*(1ll*K*a[j]%mod+w[cnt[i]]))%mod;
					}
	for(register int i=n;i>=0;--i)
		if(f[(1<<n)-1][i])
		{
			printf("%d %d\n",MAX[(1<<n)-1]+i,g[(1<<n)-1][i]);
			break;
		}
	return 0;
}