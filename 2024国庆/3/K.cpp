#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    n=1e5,m=200;
    vector<int> a(n+1);
    vector<vector<int>> mn(n+1,vector<int>(20,1e9)),mx(n+1,vector<int>(20,-1e9));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mn[i][0]=mx[i][0]=a[i];
    }
    for(int j=1;j<20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        }
    }
    auto query=[&](int l,int r){
        int k=31-__builtin_clz(r-l+1);
        return max(mx[l][k],mx[r-(1<<k)+1][k])-min(mn[l][k],mn[r-(1<<k)+1][k]);
    };
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        ll ans=0;
        for(int j=1,r=1;j<=n;j++){
            while((query(j,r)<=k&&r<=n)){
                r++;
            }
            ans+=r-j+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}