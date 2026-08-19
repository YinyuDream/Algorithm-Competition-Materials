#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return res;
}
void solve(){
    vector<ll> a(10);
    for(int i=1;i<=9;i++){
        cin>>a[i];
    }
    ll ans=1;
    if(a[1]>a[2]){
        a[1]-=a[2];
        a[3]+=a[2];
        a[2]=0;
        a[3]+=a[1]/3;
        a[1]%=3;
        if(a[1]==2){
            a[1]=0;
            a[2]++;
        }else if(a[1]==1){
            a[1]=0;
            for(int i=2;i<=9;i++){
                if(a[i]>0){
                    a[i]--;
                    if(i+1<=9){
                        a[i+1]++;
                    }else{
                        ans=10;
                    }
                    break;
                }
            }
        }
    }else{
        a[2]-=a[1];
        a[1]=0;
        a[3]+=a[1];
    }
    for(int i=2;i<=9;i++){
        ans=ans*qpow(i,a[i])%p;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}