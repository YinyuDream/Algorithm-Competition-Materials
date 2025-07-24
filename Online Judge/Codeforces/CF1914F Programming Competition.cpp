#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
struct node{
    int to,next;
}edge[maxn];
int head[maxn],sz[maxn],f[maxn],cnt;
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u)
{
    int mx=0;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        dfs(v);
        sz[u]+=sz[v];
        if(sz[mx]<sz[v]){
            mx=v;
        }
    }
    if(sz[u]-sz[mx]>=sz[mx]){
        f[u]=sz[u]-(sz[u]&1);
    }else{
        f[u]=(sz[u]-sz[mx])*2;
        int val=sz[mx]-(sz[u]-sz[mx]);
        if(f[mx]<=val){
            f[u]+=f[mx];
        }else{
            f[u]+=val-(val&1);
        }
    }
    sz[u]++;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=2;i<=n;i++){
            int fa;
            cin>>fa;
            add(fa,i);
        }
        dfs(1);
        cout<<f[1]/2<<endl;
        for(int i=1;i<=n;i++)
            head[i]=sz[i]=edge[i].to=edge[i].next=f[i]=0;
        cnt=0;
    }
    return 0;
}