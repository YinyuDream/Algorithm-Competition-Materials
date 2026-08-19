#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e7+5,mo=998244353;
int n,m,nn;
int phi[N],fn[N],fm[N],f[N],pn[N],p[N],ps;
bool b[N];
ll ans;
int pw(int x,int y=mo-2){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
void get(int *fn,int n){
	fo(i,1,n)fn[i]=(ll)phi[i]*i%mo;
	fo(i,1,ps){
		int x=p[i];
		fd(j,1,n/x)fn[j]=(fn[j]+fn[j*x])%mo;
	}
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1]=phi[1]=1;nn=max(n,m);
	fo(i,2,nn){
		if(!b[i])p[++ps]=i,phi[i]=i-1,pn[ps]=pw(i,n),f[i]=(ll)(pw(i-1)+1)*pn[ps]%mo-1;
		for(int j=1,u;(u=i*p[j])<=nn;++j){
			b[u]=1;
			if(i%p[j]==0){
				phi[u]=phi[i]*p[j];
				int v=i,v2=p[j],c=1;
				for(;v/=p[j],v2*=p[j],++c,v%p[j]==0;);
				if(v==1){
					if(c==2)f[v2]=(ll)(f[p[j]]+1)*(pn[j]-1)%mo;
					else f[v2]=(ll)f[v2/p[j]]*pn[j]%mo;
				}else f[u]=(ll)f[v]*f[v2]%mo;
				break;
			}
			phi[u]=phi[i]*(p[j]-1);
			f[u]=(ll)f[i]*f[p[j]]%mo;
		}
	}
	get(fn,n);
	get(fm,m);
	fo(i,1,min(n,m))
		ans=(ans+(ll)f[i]*fn[i]%mo*fm[i])%mo;
	ans=(ans+1)*(mo+1>>1)%mo;
	printf("%lld\n",ans);
}