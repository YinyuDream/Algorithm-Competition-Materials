#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
int T,n;
ll tot,a[maxn],sum[maxn];
ll ksm(ll a,ll b)
{
    if(b==0)return 1;
    ll ans=ksm(a,b/2);
    ans=ans*ans%p;
    if(b&1)ans=ans*a%p;
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
        tot%=p;
    }
    if(n==1){
        cout<<a[1];
        return 0;
    }
    ll inv_2=ksm(2,p-2),coe=inv_2;
    for(int i=3;i<=n;i++)
        coe=coe*((i-1)*inv_2%p+(1ll*i-1)*(i-2)%p*inv_2%p)%p;
    ll ans=coe*tot%p;
    ll cnt=1;
    for(int i=3;i<=n;i++)
        cnt=cnt*i%p*(i-1)%p*inv_2%p;
    cout<<ans*ksm(cnt,p-2)%p;
    return 0;
}