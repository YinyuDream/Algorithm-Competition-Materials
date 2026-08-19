#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=200010;

int n,p,fac[maxn],inv[maxn],num[maxn];

int mul(int a,long long b,int mo)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&p);
	fac[0]=1;
	for (int a=1;a<=(n<<1);a++)
	{
		int v=a;
		while (v%p==0)
			num[a]++,v=v/p;
		fac[a]=1ll*fac[a-1]*v%p;
		num[a]+=num[a-1];
	}
	inv[n<<1]=mul(fac[n<<1],p-2,p);
	for (int a=(n<<1)-1;a>=1;a--)
		inv[a]=1ll*inv[a+1]*(a+1)%p;
	inv[0]=1;
	
	int ans=0;
	for (int a=0;a<=n;a++)
	{
		if (num[a<<1] == num[a]<<1) ans = ans + 1ll*fac[a<<1]*inv[a]%p*inv[a]%p;
		if (ans>=p) ans-=p;
	}
	ans = 1ll * ans * mul(p-1,p-2,p) % p;
	printf("%d\n",ans);


	return 0;
}
