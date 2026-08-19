#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=25;
int T;
ll l,r;
ll pw2[maxn],pw2_3[maxn];
void work(ll l,ll r)
{
    int tot=0;
    ll ans=0;
    for(int i=0;i<maxn;i++){
        if(l*pw2[i]<=r)
            tot++;
        else break;
    }
    if(tot==1){
        cout<<1<<" "<<r-l+1<<endl;
        return;
    }
    ll mx_2=r/pw2[tot-1];
    ans+=mx_2-l+1;
    if(l*pw2_3[tot-1]<=r){
        ll mx_3=r/pw2_3[tot-1];
        ans+=(mx_3-l+1)*(tot-1);
    }
    cout<<tot<<" "<<ans<<endl;
}
int main(){
    pw2[0]=1;
    for(int i=1;i<maxn;i++)
        pw2[i]=pw2[i-1]*2;
    pw2_3[0]=1,pw2_3[1]=3;
    for(int i=2;i<maxn;i++)
        pw2_3[i]=pw2_3[i-1]*2;
    cin>>T;
    while(T--){
        cin>>l>>r;
        work(l,r);
    }
    return 0;
}