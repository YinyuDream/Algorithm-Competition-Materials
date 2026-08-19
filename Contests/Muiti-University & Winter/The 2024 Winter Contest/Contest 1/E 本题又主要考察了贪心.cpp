#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=1;
    for(int i=0;i<m;i++)
        t*=3;
    vector<pair<int,int>> f(m);
    int ans=n+1;
    for(int i=0;i<m;i++)
        cin>>f[i].first>>f[i].second;
    for(int i=0;i<t;i++){
        vector<int> vals;
        for(int j=0,now=i;j<m;j++){
            vals.push_back(now%3);
            now/=3;
        }
        auto b=a;
        for(int j=0;j<m;j++){
            auto [x,y]=f[j];
            if(vals[j]==0){
                b[x]+=3;
            }
            if(vals[j]==1){
                b[y]+=3;
            }
            if(vals[j]==2){
                b[x]++,b[y]++;
            }
        }
        int cnt=0;
        for(int j=2;j<=n;j++){
            cnt+=b[j]>b[1];
        }
        ans=min(ans,cnt+1);
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