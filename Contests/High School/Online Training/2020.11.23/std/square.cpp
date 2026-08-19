#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define js1(x) (1ll*(x)*((x)+1)%mod*499122177ll%mod)
#define js2(x) (1ll*(x)*((x)+1)%mod*(2*(x)+1)%mod*166374059ll%mod)
#define js3(x) (1ll*(x)*(x)%mod*((x)+1)%mod*((x)+1)%mod*748683265ll%mod)
#define Js1(x,y) ((js1(y)-js1((x)-1))%mod)
#define Js2(x,y) ((js2(y)-js2((x)-1))%mod)
#define Js3(x,y) ((js3(y)-js3((x)-1))%mod)
#define add(a,b) a=((a)+(b))%mod
#define sqr(x) (1ll*(x)*(x)%mod)
#define sq3(x) (1ll*(x)*(x)%mod*(x)%mod)
#define mod 998244353
#define Mod 998244351
#define ll long long
#define file
using namespace std;

ll ans,sum,ans1,ans2,sum0,sum1,sum2,L;
ll S[1000001][3];
int N,n,m,i,j,k,l;
map<int,ll> S2[3];
map<int,ll> :: iterator I;

int gcd(int x,int y) {int r=x%y; while (r) x=y,y=r,r=x%y; return y;}
void swap(int &x,int &y) {int z=x;x=y;y=z;}
ll qpower(ll a,int b) {ll ans=1; while (b) {if (b&1) ans=ans*a%mod;a=a*a%mod;b>>=1;} return ans;}

namespace work1{
	int i,j,k,l;
	ll a[11];
	
	ll js(ll x)
	{
		ll ans=0,s1,s2;
		fo(i,1,10)
		{
			s1=a[i],s2=1;
			fo(j,1,10)
			if (i!=j)
			s1=s1*(x-j)%mod,s2=s2*(i-j)%mod;
			add(ans,s1*qpower(s2,Mod));
		}
		return ans;
	}
}

namespace work2{
	int p[1000001],len,i,j,k,l;
	bool f[1000001];
	ll phi[1000001];
	
	void init()
	{
		phi[1]=1;
		fo(i,2,N)
		{
			if (!f[i]) p[++len]=i,phi[i]=i-1;
			fo(j,1,len)
			if (1ll*i*p[j]<=N)
			{
				f[i*p[j]]=1;
				if (!(i%p[j])) {phi[i*p[j]]=phi[i]*p[j];break;}
				phi[i*p[j]]=phi[i]*(p[j]-1);
			}
			else break;
		}
	}
}

void init()
{
	work2::init();
	fo(i,1,N)
	{
		S[i][0]=(S[i-1][0]+work2::phi[i])%mod;
		S[i][1]=(S[i-1][1]+work2::phi[i]*i)%mod;
		S[i][2]=(S[i-1][2]+work2::phi[i]*i%mod*i)%mod;
	}
}
ll get(int n,int tp)
{
	int i,j,k,l;
	ll ans=0,s;
	
	if (n<=N) return S[n][tp];
	I=S2[tp].find(n);
	if (I!=S2[tp].end()) return I->second;
	
	j=2;
	switch (tp)
	{
		case 0:{ans=js1(n);break;}
		case 1:{ans=js2(n);break;}
		case 2:{ans=js3(n);break;}
	}
	while (j<=n)
	{
		k=n/(n/j);
		switch (tp)
		{
			case 0:{s=k-j+1;break;}
			case 1:{s=Js1(j,k);break;}
			case 2:{s=Js2(j,k);break;}
		}
		add(ans,-s*get(n/j,tp));
		j=k+1;
	}
	S2[tp][n]=ans;
	return ans;
}
ll Get(int n,int tp)
{
	if (n<=N) return S[n][tp];
	return S2[tp][n];
}

void Work1()
{
	if (n<=10)
	{
		fo(L,1,n)
		{
			sum=(js2(L-1)*2%mod-sqr(L))%mod;
			add(ans1,sum*(n-L+1)%mod*(m-L+1));
		}
	}
	else
	{
		fo(L,1,10)
		{
			sum=(js2(L-1)*2%mod-sqr(L))%mod;
			add(ans1,sum*(n-L+1)%mod*(m-L+1));
			work1::a[L]=ans1;
		}
		ans1=work1::js(n);
	}
}
void Work2()
{
	int i,j,k,l;
	ll s1,s2,s3,ls1=0,ls2=0,ls3=0;
	init();
	get(n,0),get(n,1),get(n,2);
	
	j=1;
	while (j<=n)
	{
		k=n/(n/j);l=n/j;
		s1=Get(k,0);s2=Get(k,1);s3=Get(k,2);
		add(sum0,(s1-ls1)*js1(l));
		add(sum1,(s2-ls2)*js2(l));
		add(sum2,(s3-ls3)*js3(l));
		ls1=s1;ls2=s2;ls3=s3;
		j=k+1;
	}
}

int main()
{
	freopen("square.in","r",stdin);
	#ifdef file
	freopen("square.out","w",stdout);
	#endif
	
	scanf("%d%d",&n,&m);if (n>m) swap(n,m);N=floor(pow(n,(double)2.0/3));
	Work1();
	Work2();
	ans2=(sum0*(n+1)%mod*(m+1)%mod-sum1*(n+m+2)%mod+sum2)%mod;
	ans2=ans2*2%mod;
	
	ans=(ans1+ans2)%mod;
	printf("%lld\n",(ans+mod)%mod);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}