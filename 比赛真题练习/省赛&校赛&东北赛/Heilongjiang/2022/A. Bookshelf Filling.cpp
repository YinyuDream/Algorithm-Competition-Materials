#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,n,m,h,ans,delta,pos;
bool check(int x)
{
    int cnt=x/(h-b);
    if(x%(h-b)!=0)cnt++;
    if(pos+cnt*b>n+m-x)return false;
    else return true;
}
signed main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>n>>m>>h;
        ans=m+n;
        delta=(n/b)*(h-a);
        if(delta>m-1){
            ans-=m-1;
            cout<<ans<<endl;
            continue;
        }
        ans-=delta;
        if(b==h){
            cout<<ans<<endl;
            continue;
        }
        pos=n/b*b;
        m-=delta;
        int l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        cout<<ans-r<<endl;
    }
    return 0;
}