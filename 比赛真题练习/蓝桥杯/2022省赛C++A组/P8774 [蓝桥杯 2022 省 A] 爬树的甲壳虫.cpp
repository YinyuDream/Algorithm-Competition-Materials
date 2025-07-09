#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
int n;
ll x[maxn],y[maxn],f[maxn];
ll ksm(ll a,ll b)
{
    if(b==0)return 1;
    ll ans=ksm(a,b/2);
    ans*=ans;
    ans%=p;
    if(b%2==1){
        ans*=a;
        ans%=p;
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]+1)*y[i]%p*ksm(y[i]-x[i],p-2)%p;
    }
    cout<<f[n];
    return 0;
}