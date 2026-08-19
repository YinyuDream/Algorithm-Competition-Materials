#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll p=1e9+7;
int T;
ll n,m,k;
ll inv[maxn],fac[maxn],ifac[maxn],q[maxn],pw[maxn],f[maxn];
ll ksm(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*ifac[b]%p*ifac[a-b]%p;
}
int main(){
	cin>>T;
    inv[1]=fac[0]=ifac[0]=1;
    for(int i=2;i<maxn;i++) inv[i]=(p-p/i)*inv[p%i]%p;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%p;
    for(int i=1;i<maxn;i++) ifac[i]=ifac[i-1]*inv[i]%p;
	while(T--){
		cin>>n>>m>>k;
        ll sum_f=0;
        for(int i=1,u,v,w;i<=m;i++){
            cin>>u>>v>>w;
            sum_f=(sum_f+w)%p;
        }
        ll tot=n*(n-1)/2%p;
        ll all=ksm(ksm(tot,p-2),k);
        pw[0]=1;
        for(int i=1;i<=k;i++)
            pw[i]=pw[i-1]*(tot-1)%p;
        for(int i=1;i<=k;i++)
            q[i]=comb(k,i)*pw[k-i]%p*all%p;
        ll sum1=0,sum2=0;
        for(int i=1;i<=k;i++)
            sum1=(sum1+1ll*i*(i-1)/2%p*q[i])%p;
        for(int i=1;i<=k;i++)
            sum2=(sum2+i*q[i])%p;
        sum1=sum1*m%p;
        sum2=sum2*sum_f%p;
        cout<<(sum1+sum2)%p<<endl;
	}
	return 0;
}