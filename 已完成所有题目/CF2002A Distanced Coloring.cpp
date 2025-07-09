#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<min(m,k)*min(n,k)<<endl;    
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}