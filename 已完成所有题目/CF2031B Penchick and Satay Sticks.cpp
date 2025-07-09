#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    vector<vector<int>> mn(n+1,vector<int>(20,0)),mx(n+1,vector<int>(20,0));
    for(int i=1;i<=n;i++){
        mn[i][0]=mx[i][0]=a[i];
    }
    for(int i=1;i<20;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
            mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
        }
    }
    auto query=[&](int l,int r){
        int k=log2(r-l+1);
        return make_pair(min(mn[l][k],mn[r-(1<<k)+1][k]),max(mx[l][k],mx[r-(1<<k)+1][k]));
    };
    bool can=true;
    for(int i=1;i<n;i++){
        int l=pos[i],r=pos[i+1];
        if(l>r){
            swap(l,r);
        }
        auto [mn,mx]=query(l,r);
        can&=(mn==l&&mx==r);
    }
    if(can){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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