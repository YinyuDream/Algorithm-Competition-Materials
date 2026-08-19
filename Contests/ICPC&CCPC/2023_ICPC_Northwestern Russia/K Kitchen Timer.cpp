#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll t[62],s[62];
void solve()
{
    ll x,cnt=0;
    cin>>x;
    for(int i=60;i>=1;i--){
        while(x>=(1ll<<i)-1){
            x-=((1ll<<i)-1);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}