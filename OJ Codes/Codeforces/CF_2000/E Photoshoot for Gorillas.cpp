#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n+2,vector<int>(m+2));
    for(int i=1;i+k-1<=n;i++)
        for(int j=1;j+k-1<=m;j++)
            a[i][j]++,a[i+k][j]--,a[i][j+k]--,a[i+k][j+k]++;
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            q.push(a[i][j]);
    int w;
    cin>>w;
    vector<int> x(w);
    for(int i=0;i<w;i++)
        cin>>x[i];
    sort(x.begin(),x.end());
    ll ans=0;
    for(int i=w-1;i>=0;i--)
        ans+=1ll*x[i]*q.top(),q.pop();
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