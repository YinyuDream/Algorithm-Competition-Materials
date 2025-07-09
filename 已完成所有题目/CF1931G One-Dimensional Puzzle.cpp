#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+10;
const ll p=998244353;
int T,n;
int a,b,c,d;
int f[maxn];
ll inv[maxn],fac[maxn],facinv[maxn];
ll ksm(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll comb(int n,int m){
    if(n<m) return 0;
    return fac[n]*facinv[m]%p*facinv[n-m]%p;
}
int main(){
    inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]=(p-p/i)*inv[p%i]%p;
    fac[0]=facinv[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=fac[i-1]*i%p;
        facinv[i]=facinv[i-1]*inv[i]%p;
    }
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        if(abs(a-b)>1){
            cout<<0<<endl;
            continue;
        }
        if(!a&&!b){
            if(!c||!d) cout<<1<<endl;
            else cout<<0<<endl;
            continue;
        }
        ll ans=0;
        for(int i=1;i<=a+b;i++)
            f[i]=(i&1)+1;
        int cnt_c=0,cnt_d=0;
        if(a<=b){
            for(int i=1;i<a+b;i++){
                if(f[i]==1&&f[i+1]==2) cnt_c++;
                else cnt_d++;
            }
            cnt_c++;
            if(f[a+b]==1)cnt_c++;
            if(f[a+b]==2)cnt_d++;
            ans+=comb(cnt_c+c-1,cnt_c-1)*comb(cnt_d+d-1,cnt_d-1)%p;
        }
        if(b<=a){
            cnt_c=0,cnt_d=0;
            for(int i=1;i<=a+b;i++)
                f[i]=((i-1)&1)+1;
            for(int i=1;i<a+b;i++){
                if(f[i]==1&&f[i+1]==2) cnt_c++;
                else cnt_d++;
            }
            cnt_d++;
            if(f[a+b]==1)cnt_c++;
            if(f[a+b]==2)cnt_d++;
            
            ans+=comb(cnt_c+c-1,cnt_c-1)*comb(cnt_d+d-1,cnt_d-1)%p;
        }
        ans%=p;
        cout<<ans<<endl;
    }
    return 0;
}