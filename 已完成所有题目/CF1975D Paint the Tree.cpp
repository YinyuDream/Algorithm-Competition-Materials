#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,a,b;
struct node{
    int to,nxt;
}edge[maxn];
int head[maxn],tot;
void add(int u,int v){
    edge[++tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot;
}
int stk[maxn],now[maxn],top,sum;
void dfs(int u,int f)
{
    stk[++top]=u;
    if(u==b){
        for(int i=1;i<=top;i++)
            now[i]=stk[i];
        sum=top;
    }
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        dfs(v,u);
    }
    top--;
}
int dfs2(int u,int f){
    int mx=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        mx=max(mx,dfs2(v,u));
    }
    return mx+1;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        cin>>a>>b;
        for(int i=1;i<=n;i++)
            head[i]=0;
        for(int i=1;i<=tot;i++)
            edge[i].to=edge[i].nxt=0;
        tot=top=sum=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(a,a);
        int mid=now[(sum+1)/2],ans=sum-(sum+1)/2+2*(n-1);
        int mx_dis=dfs2(mid,mid)-1;
        ans-=mx_dis;
        cout<<ans<<endl;
    }
    return 0;
}