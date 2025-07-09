#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
typedef long long ll;
int Q,sum[maxn];
ll x,mx;
int main(){
    cin>>x>>Q;
    mx=1;
    while(mx<=x)
        mx<<=1;
    for(int i=1;i<=mx*2;i++)
        sum[i]=sum[i-1]+(__gcd((i*x)^x,x)==1);
    while(Q--){
        ll l,r,cnt=0;
        cin>>l>>r;
        if(r-l+1<=mx){
            l=(l-1)%mx+1;
            r=(r-1)%mx+1;
            if(r<l)r+=mx;
            cout<<sum[r]-sum[l-1]<<endl;
        }else{
            ll ans=0;
            ll real_l=l,real_r=r;
            l=(l-1)%mx+1;
            r=(r-1)%mx+1;
            ans=sum[mx]-sum[l-1]+sum[r];
            real_l+=mx-l+1;
            real_r-=r;
            ans+=sum[mx]*((real_r-real_l+1)/mx);
            cout<<ans<<endl;
        }
    }
    return 0;
}