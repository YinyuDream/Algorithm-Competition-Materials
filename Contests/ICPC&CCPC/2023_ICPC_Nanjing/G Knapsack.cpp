#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,W,k;
struct node{
    int w,v;
}a[maxn];
bool operator<(node a,node b){
    return a.w>b.w;
}
priority_queue<int,vector<int>,greater<int> > q;
long long sum,ans,dp[maxn][maxn];
int main(){
    cin>>n>>W>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].w>>a[i].v;
    sort(a+1,a+n+1);
    for(int i=1;i<=k;i++){
        q.push(a[i].v);
        sum+=a[i].v;
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<=W;j++){
            dp[i][j]=dp[i+1][j];
            if(j-a[i].w>=0)
                dp[i][j]=max(dp[i][j],dp[i+1][j-a[i].w]+a[i].v);
        }
    }
    for(int i=k+1;i<=n;i++){
        ans=max(ans,dp[i][W]+sum);
        q.push(a[i].v);
        sum+=a[i].v;
        sum-=q.top();
        q.pop();
    }
    ans=max(ans,sum);
    cout<<ans<<endl;
}