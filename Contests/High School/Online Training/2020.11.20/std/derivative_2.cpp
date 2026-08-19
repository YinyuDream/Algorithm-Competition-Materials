#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
#define mo 998244353
#define maxn 131072
using namespace std;

ll n,m,p,q,i,j;

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int bt[maxn],lim;
void dft(ll *a,int sig){
	for(int i=0;i<lim;i++) if (i<bt[i]) swap(a[i],a[bt[i]]);
	for(int mid=1;mid<lim;mid<<=1){
		ll gn=ksm(3,(mo-1)/(mid<<1));
		if (sig<0) gn=ksm(gn,mo-2);
		for(int i=0;i<lim;i+=mid<<1){
			ll g=1;
			for(int j=0;j<mid;j++,g=g*gn%mo){
				ll x=a[i+j],y=a[i+j+mid]*g;
				a[i+j]=(x+y)%mo,a[i+j+mid]=(x-y)%mo;
			}
		}
	}
	if (sig<0){
		ll inv=ksm(lim,mo-2);
		for(int i=0;i<lim;i++) a[i]=(a[i]*inv%mo+mo)%mo;
	}
}

ll s[maxn],x[maxn];
void multi(ll *a,ll *b,ll *c){
	static ll A[maxn],B[maxn],C[maxn];
	memcpy(A,a,sizeof(A)),memcpy(B,b,sizeof(B));
	dft(A,1),dft(B,1);
	for(int i=0;i<lim;i++) C[i]=A[i]*B[i]%mo;
	dft(C,-1);
	for(int i=lim-1;i>=m;i--) (C[i-m]+=C[i]*p)%=mo,C[i]=0;
	memcpy(c,C,sizeof(C));
}

int main(){
	freopen("derivative.in","r",stdin);
	freopen("derivative.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for(lim=1;lim<=m*2;lim<<=1);
	for(i=1;i<lim;i++) bt[i]=(bt[i>>1]>>1)|((i&1)*(lim>>1));
	x[0]=1,x[1]=q,s[0]=1;
	for(ll y=n*m;y;y/=2,multi(x,x,x)) if (y&1) 
		multi(x,s,s);
	printf("%lld\n",(s[0]+mo)%mo);
}