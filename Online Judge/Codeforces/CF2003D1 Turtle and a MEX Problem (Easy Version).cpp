#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
        sort(a[i].begin(),a[i].end());
        auto it=unique(a[i].begin(),a[i].end());
        a[i].erase(it,a[i].end());
    }
    int mx=0;
    for(int i=0;i<n;i++){
        int len=a[i].size(),pos=-1;
        for(int j=0;j<len;j++){
            if(a[i][j]!=j){
                pos=j;
                break;
            }
        }
        if(pos==-1){
            mx=max(mx,len+1);
            continue;
        }
        if(a[i][pos]-pos>=2){
            mx=max(mx,pos+1);
            continue;
        }
        bool flag=false;
        for(int j=pos;j<len;j++){
            if(a[i][j]-j>=2){
                flag=true;
                mx=max(mx,j+1);
                break;
            }
        }
        if(flag){
            continue;
        }
        mx=max(mx,len+1);
    }
    ll ans=0;
    //for(int i=0;i<=m;i++)
    //    ans+=max(i,mx);
    ans=1ll*min(m+1,mx+1)*mx;
    if(m>mx){
        ans+=1ll*m*(m+1)/2-1ll*mx*(mx+1)/2;
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