#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,c;
    cin>>n>>c;
    vector<int>a(n);
    vector<int>sum(n);
    vector<int>pre_max(n);
    vector<int>ans(n,1e9);
    set<int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    sum[0]=pre_max[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
        pre_max[i]=max(pre_max[i-1],a[i]);
    }
    if(pre_max[n-1]<=a[0]+c){
        ans[0]=0;
    }
    for(int i=1;i<n;i++)
        if(pre_max[i-1]<a[i]&&pre_max[n-1]<=a[i]&&c+a[0]<a[i])
            ans[i]=0;
    for(auto i:ans){
        cout<<i<<' ';
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}