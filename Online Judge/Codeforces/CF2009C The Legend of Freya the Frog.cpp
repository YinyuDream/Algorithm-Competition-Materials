#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int a,b,x;
    cin>>a>>b>>x;
    int u=a/x+(a%x!=0),v=b/x+(b%x!=0);
    u=max(u,v);
    cout<<u+max(u-1,v)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}