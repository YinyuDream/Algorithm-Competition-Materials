#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll n,m,ans=1;
ll pw2[100];
ll ksm(ll a,ll b)
{
    if(b==0)return 1;
    ll ans=ksm(a,b/2);
    ans=ans*ans%p;
    if(b&1)ans=ans*a%p;
    return ans;
}
int main(){
    for(int i=0;i<=32;i++)
        pw2[i]=(1<<(i+1))-1;
    cin>>n>>m;
    int st=(int)log2(n+1)-1,ed=(int)log2(n+m)-1;
    if(st==ed){
        ans=(1-ksm(1<<(st+1),p-2))%p;
        ans=ksm(ans,m);   
    }
    else{
        ans=(1-ksm(1<<(st+1),p-2))%p;
        ans=ksm(ans,pw2[st+1]-n);
        for(int i=st+1;i<ed;i++){
            ll num=(1-ksm(1<<(i+1),p-2))%p;
            num=ksm(num,pw2[i+1]-pw2[i]);
            ans=ans*num%p;
        }
        ans=ans*ksm((1-ksm(1<<(ed+1),p-2))%p,n+m-pw2[ed])%p;
    }
    cout<<(ans+p)%p;
    return 0;
}