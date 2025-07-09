#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10,p=1e9+7;
int T,n,k;
int r[maxn],c[maxn],book[maxn];
ll fac[maxn],inv[maxn],finv[maxn];
ll comb(ll a,ll b)
{
    if(a<b)return 0;
    return fac[a]*finv[b]%p*finv[a-b]%p;
}
int main(){
    fac[0]=fac[1]=inv[1]=finv[0]=finv[1]=1;
    for(int i=2;i<maxn;i++){
        fac[i]=fac[i-1]*i%p;
        inv[i]=(p-p/i)*inv[p%i]%p;
        finv[i]=finv[i-1]*inv[i]%p;
    }
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            book[i]=0;
        for(int i=1;i<=k;i++){
            cin>>r[i]>>c[i];
            book[r[i]]=1;
            book[c[i]]=1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(book[i]==0)
                cnt++;
        ll ans=0;
        if(cnt%2==0){
            for(int i=0;i<=cnt;i+=2)
                ans=(ans+comb(cnt,i)*fac[cnt-i]%p*finv[(cnt-i)/2])%p;
        }else{
            for(int i=1;i<=cnt;i+=2)
                ans=(ans+comb(cnt,i)*fac[cnt-i]%p*finv[(cnt-i)/2])%p;
        }
        cout<<ans%p<<endl;
    }
    return 0;
}