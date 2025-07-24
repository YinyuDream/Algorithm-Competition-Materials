#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int ans=0;
    auto check([&](int a1,int a2,int b1,int b2){
        int cnt1=0,cnt2=0;
        if(a1>b1)cnt1++;
        if(a1<b1)cnt2++;
        if(a2>b2)cnt1++;
        if(a2<b2)cnt2++;
        return cnt1>cnt2;
    });
    ans+=check(a1,a2,b1,b2);
    ans+=check(a1,a2,b2,b1);
    ans+=check(a2,a1,b1,b2);
    ans+=check(a2,a1,b2,b1);
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