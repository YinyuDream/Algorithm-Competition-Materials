#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int p=n/x+(n%x!=0);
    int q=n/y+(n%y!=0);
    cout<<max(p,q)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}