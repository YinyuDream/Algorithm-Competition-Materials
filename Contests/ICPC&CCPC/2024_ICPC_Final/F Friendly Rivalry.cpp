#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
constexpr double eps = 1e-8;
const int maxn=1e3+10;
pii p[maxn],ele[maxn];
int f[maxn],sz[maxn],dp[maxn][maxn],pre[maxn][maxn];
ll d[maxn*maxn],cnt;
set<int> s,ans;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>p[i].first>>p[i].second;
    }
    auto dist = [&](pii a,pii b){
        return (1ll*a.first-b.first)*(a.first-b.first)+(1ll*a.second-b.second)*(a.second-b.second);
    };
    for(int i=1;i<=2*n;i++){
        for(int j=i+1;j<=2*n;j++){
            d[++cnt]=dist(p[i],p[j]);
        }
    }
    sort(d+1,d+1+cnt);
    function<int(int)> find=[&](int x){
        return f[x]==x?x:f[x]=find(f[x]);
    };
    auto merge=[&](int x,int y){
        x=find(x),y=find(y);
        if(x!=y){
            if(sz[x]>sz[y]){
                swap(x,y);
            }
            f[x]=y;
            sz[y]+=sz[x];
        }
    };
    auto check=[&](int pos){
        ll lim=d[pos];
        for(int i=1;i<=n*2;i++)
            f[i]=i,sz[i]=1;
        for(int i=1;i<=n*2;i++){
            for(int j=i+1;j<=n*2;j++){
                if(dist(p[i],p[j])<lim){
                    merge(i,j);
                }
            }
        }
        s.clear();
        int top=0;
        for(int i=1;i<=n*2;i++){
            int x=find(i);
            if(s.count(x)){
                continue;
            }
            s.insert(x);
            ele[++top]={sz[x],x};
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=top;i++){
            for(int j=0;j<=n;j++){
                if(dp[i-1][j]){
                    dp[i][j]=1;
                }
                if(j>=ele[i].first&&dp[i-1][j-ele[i].first]){
                    dp[i][j]=1;
                }
            }
        }
        return dp[top][n];
    };
    cout<<fixed<<setprecision(10)<<endl;
    int l=1,r=cnt;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<sqrt(d[r])<<endl;
    for(int i=1;i<=2*n;i++){
        f[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=n*2;i++){
        for(int j=i+1;j<=n*2;j++){
            if(dist(p[i],p[j])<d[r]){
                merge(i,j);
            }
        }
    }
    s.clear();
    int top=0;
    for(int i=1;i<=n*2;i++){
        int x=find(i);
        if(s.count(x)){
            continue;
        }
        s.insert(x);
        ele[++top]={sz[x],x};
    }
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    dp[0][0]=1;
    for(int i=1;i<=top;i++){
        for(int j=0;j<=n;j++){
            if(dp[i-1][j]){
                dp[i][j]=1;
                pre[i][j]=0;
            }
            if(j>=ele[i].first&&dp[i-1][j-ele[i].first]){
                dp[i][j]=1;
                pre[i][j]=1;
            }
        }
    }
    for(int i=top,j=n;i>0;i--){
        if(pre[i][j]){
            ans.insert(ele[i].second);
            j-=ele[i].first;
        }
    }
    for(int i=1;i<=n*2;i++){
        int x=find(i);
        if(ans.count(x)){
            cout<<i<<endl;
        }
    }
    return 0;
}