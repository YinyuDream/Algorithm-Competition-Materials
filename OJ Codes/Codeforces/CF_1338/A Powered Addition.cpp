#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),mx(n+1);
    mx[0]=-1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    int val=0;
    for(int i=1;i<=n;i++){
        val=max(val,mx[i]-a[i]);
    }
    int ans=0;
    while(val){
        val>>=1;
        ans++;
    }
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