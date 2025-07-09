#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,cnt;
int c[maxn],t[maxn],fa[maxn];
ll ans;
vector<int>vec[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1,k;i<=m;i++){
        cin>>k>>c[i];
        for(int j=1,x;j<=k;j++){
            cin>>x;
            vec[i].push_back(x);
        }
    }
    for(int i=1;i<=m;i++)
        t[i]=i;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(t+1,t+m+1,[&](int x,int y){return c[x]<c[y];});
    for(int i=1;i<=m;i++){
        int x=t[i];
        int k=vec[x].size();
        for(int j=1;j<k;j++){
            int u=find(vec[x][j-1]);
            int v=find(vec[x][j]);
            if(u!=v){
                fa[u]=v;
                ans+=c[x];
                cnt++;
            }
        }
    }
    if(cnt==n-1)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}