#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
int T,n;
ll a[maxn];
ll ksm(ll a,ll b)
{
    if(b==0)
        return 1;
    ll ans=ksm(a,b/2);
    ans=ans*ans%p;
    if(b%2==1)
        ans=ans*a%p;
    return ans;

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll ans=1;
    for(int i=1;i<=n;i+=3){
        sort(a+i,a+i+3);
        if(a[i]==a[i+2])
            ans=ans*3%p;
        if(a[i]==a[i+1]&&a[i+1]<a[i+2])
            ans=ans*2%p;
    }
    n/=3;
    for(int i=n/2+1;i<=n;i++)
        ans=ans*i%p;
    for(int i=1;i<=n/2;i++)
        ans=ans*ksm(i,p-2)%p;
    cout<<ans<<endl;
    return 0;
}