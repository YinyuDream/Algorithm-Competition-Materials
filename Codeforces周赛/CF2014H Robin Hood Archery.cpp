#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),xor_sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xor_sum[i]=xor_sum[i-1]^a[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int val=xor_sum[r]^xor_sum[l-1];
        cout<<(val?"NO":"YES")<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}