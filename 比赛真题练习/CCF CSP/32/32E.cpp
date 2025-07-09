#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n,m,l,k;
int c[maxn],d[maxn],u[maxn],v[maxn];
struct node{
    int to,next,wt;
}edge[maxn];
int f[maxn][maxn];//考虑到第i个点，经过了j个点的最大路径长度
int head[maxn],cnt;
void add(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    edge[cnt].wt=w;
}
int main(){
    cin>>n>>m>>l>>k;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=m;i++)
        cin>>u[i],u[i]++;
    for(int i=1;i<=m;i++)
        cin>>v[i],v[i]++;
    for(int i=1;i<=m;i++)
        cin>>d[i];
    for(int i=1;i<=m;i++)
        add(v[i],u[i],d[i]);
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            for(int e=head[i];e;e=edge[e].next){
                int to=edge[e].to;
                if(c[to]<c[i]){
                    f[i][j]=max(f[i][j],f[to][j-1]+edge[e].wt);
                }
            }
        }
    }
    int ans=0;
    for(int i=2;i<=l;i++)
        ans=max(f[n][i],ans);
    cout<<ans<<endl;
    return 0;
}