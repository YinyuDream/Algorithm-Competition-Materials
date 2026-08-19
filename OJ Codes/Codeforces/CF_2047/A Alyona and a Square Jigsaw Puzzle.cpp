#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    set<int> st;
    for(int i=1;i<=200;i+=2){
        st.insert(i*i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(st.count(sum[i])){
            ans++;
        }
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