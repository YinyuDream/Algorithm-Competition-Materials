#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int count(ll x)
{
    int ans=0;
    while(x){
        ans++;
        x>>=1;
    }
    return ans;
}
ll work(ll P,ll m)
{
    if(m==0)
        return (P-1)%P==1;
    int num=count(m);
    ll ans=0;
    for(int i=num-1;i>=0;i--){
        if((m>>i)&1){
            ll mn=(((m>>i)^1)^((P-1)>>i))<<i;
            ll mx=mn+(1ll<<i)-1;
            mn--,mx--;
            ll mnk=floor(1.0*mn/P),mxk=floor(1.0*mx/P);
            if(mn%P!=0)
                mnk++;
            ans+=mxk-mnk+1;
        }
    }
    if((m^(P-1))%P==1)
        ans++;
    return ans;
}
int main(){
    scanf("%d",&T);
    while(T--){
        ll P,m;
        scanf("%lld%lld",&P,&m);
        printf("%lld\n",work(P,m));
    }
    return 0;
}