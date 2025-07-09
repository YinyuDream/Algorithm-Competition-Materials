#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<ll> a(n+1),sum(n+1,0);
    vector<vector<int>>nxt(n+2,vector<int>(20,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=i+1,r=n+1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(sum[mid-1]-sum[i-1]<=k){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        nxt[i][0]=r;
    }
    for(int i=0;i<20;i++){
        nxt[n+1][i]=n+1;
    }
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int now=i;
        int res=0;
        for(int j=19;j>=0;j--){
            if((m>>j)&1){
                res+=nxt[now][j]-now;
                now=nxt[now][j];
            }
        }
        ans=max(ans,res);
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