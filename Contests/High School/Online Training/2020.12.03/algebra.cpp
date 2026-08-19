#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=10;
int n,m,k;
ll ans,f[maxn][maxn][maxn][maxn][maxn][maxn];
ll C(ll x,ll y)
{
	ll num=1;
	for(ll i=1;i<=x;i++)
		num*=i;
	for(ll i=1;i<=y;i++)
		num/=i;
	for(ll i=1;i<=x-y;i++)
		num/=i;
	return num;
}
void solve()
{
	f[0][m][0][0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int a0=0;a0<=m;a0++)
			for(int a1=0;a0+a1<=m;a1++)
				for(int a2=0;a0+a1+a2<=m;a2++)
					for(int a3=0;a0+a1+a2+a3<=m;a3++)
						for(int a4=0;a0+a1+a2+a3+a4<=m;a4++)
							for(int k0=0;k0<=k&&k0<=a0;k0++)
								for(int k1=0;k0+k1<=k&&k1<=a1;k1++)
									for(int k2=0;k0+k1+k2<=k&&k2<=a2;k2++)
										for(int k3=0;k0+k1+k2+k3<=k&&k3<=a3;k3++)
											for(int k4=0;k0+k1+k2+k3+k4<=k&&k4<=a4;k4++)
												if(a0+a1+a2+a3+a4==m&&k0+k1+k2+k3+k4==k)
													f[i+1][a0-k0][a1-k1+k0][a2-k2+k1][a3-k3+k2][a4-k4+k3]+=f[i][a0][a1][a2][a3][a4]*C(a0,k0)*C(a1,k1)*C(a2,k2)*C(a3,k3)*C(a4,k4);
	if(k==0)     printf("%lld",f[n][m][0][0][0][0]);
	else if(k==1)printf("%lld",f[n][0][m][0][0][0]);
	else if(k==2)printf("%lld",f[n][0][0][m][0][0]);
	else if(k==3)printf("%lld",f[n][0][0][0][m][0]);
	else if(k==4)printf("%lld",f[n][0][0][0][0][m]);											
}
int main(){
	freopen("algebra.in","r",stdin);
	freopen("algebra.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k=min(k,n-k);
	solve();
	return 0;
}
