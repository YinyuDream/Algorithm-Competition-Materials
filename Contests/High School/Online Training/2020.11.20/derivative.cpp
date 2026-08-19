#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,p=998244353;
int n,k,a,b,ans;
int jc[maxn];
int qpow(int a,int b)
{
	if(!b)return 1;
	int c=qpow(a,b/2);
	c=1ll*c*c%p;
	if(b&1)c=1ll*c*a%p;
	return c;
}
int main(){
	freopen("derivative.in","r",stdin);
	freopen("derivative.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&a,&b);
	jc[0]=0;
	for(int i=1;i<=n*k;i++)
		jc[i]=1ll*jc[i-1]*i%p;
	for(int i=0;i<=n;i++)
		ans=(1ll*ans+qpow(a,i)*qpow(b,k*i)%p*jc[n*k]%p*qpow(jc[n*k-i*k],p-2)%p*qpow(jc[i*k],p-2))%p;
	printf("%d",ans);
	return 0;
}
