#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=3010,mod=998244353;
template <typename Tp> int getmin(Tp &x,Tp y){return y<x?x=y,1:0;}
template <typename Tp> int getmax(Tp &x,Tp y){return y>x?x=y,1:0;}
template <typename Tp> void read(Tp &x)
{
	x=0;char ch=getchar();int f=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') ch=getchar(),f=1;
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	if(f) x=-x;
}
int n,A,B,P,Q,invP,invQ,k,tmp,ans,f[maxn],p[maxn],mp[maxn],mq[maxn];
int pls(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int dec(int x,int y){return x-y<0?x-y+mod:x-y;}
int power(int x,int y)
{
	int res=1;
	for(;y;y>>=1,x=(ll)x*x%mod)
	  if(y&1)
	    res=(ll)res*x%mod;
	return res;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	mp[0]=mq[0]=1;
	read(n);read(A);read(B);
	P=(ll)A*power(B,mod-2)%mod;
	Q=dec(1,P);
	invP=power(P,mod-2);
	invQ=power(Q,mod-2);
	for(int i=1;i<=n+5;i++)
	{
		mp[i]=(ll)mp[i-1]*P%mod;
		mq[i]=(ll)mq[i-1]*Q%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++) p[i]=(p[i]+(ll)mp[j]*mq[i-j])%mod;
		p[i]=(ll)p[i]*mp[2]%mod*mq[2]%mod;
	}
	f[1]=1;f[2]=0;f[3]=1;
	if(n<=3){printf("%d\n",f[n]);return 0;}
	for(int i=4;i<=n;i++)
	{
		for(int j=i-5;j>=1;j--)
		{
			f[i]=(f[i]+(ll)(i-5-j)*p[j]%mod*f[j])%mod;
			f[i]=(f[i]+(ll)p[j]*(invP+invQ)%mod*f[j])%mod;
		}
		f[i]=(f[i]+(ll)p[i-4]*invP%mod*invQ%mod*f[i-4])%mod;
		for(int j=i-3;j;j--)
		  f[i]=(f[i]+((ll)mp[j]*mq[1]+(ll)mp[1]*mq[j])%mod*f[j])%mod;
		f[i]=(f[i]+(mp[i-2]+mq[i-2])*(ll)f[i-2])%mod;
	}
	k=dec(dec(1,mp[n]),mq[n]);
	k=power(k,mod-2);
	for(int i=n-2;~i;i--) tmp=(tmp+(ll)mp[i]*mq[n-2-i])%mod;
	tmp=(ll)tmp*mp[1]%mod*mq[1]%mod;
	for(int i=n-4;i;i--) ans=(ans+(ll)p[i]*f[i])%mod;
	ans=((ll)ans*n+(ll)tmp*n%mod*f[n-2])%mod*k%mod;
	printf("%d\n",ans);
	//for(int i=1;i<=n;i++) fprintf(stderr,"%d ",f[i]);
	//fprintf(stderr,"\n");
	return 0;
}
