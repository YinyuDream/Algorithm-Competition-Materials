#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=1e9;
    for(int i=0;i<=10;i++)
        ans=min(ans,abs(a-i)+abs(b-i)+abs(c-i));
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