#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T,n,m,q;
struct node{
    int u,v,w;
}a[maxn];
bool operator <(node u,node v){
    return u.w>v.w;
}
int fa[maxn],sz[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
map<int,ll>mp;
int main(){
    scanf("%d",&T);
    while(T--){
        mp.clear();
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++)
            fa[i]=i,sz[i]=1;
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            a[i]={u,v,w};
        }
        sort(a+1,a+m+1);
        ll ans=0;
        for(int i=1;i<=m;i++){
            int fx=find(a[i].u),fy=find(a[i].v);
            if(fx!=fy){
                fa[fx]=fy;
                ans+=1ll*sz[fx]*sz[fy];
                sz[fy]+=sz[fx];
            }
            if(mp.find(a[i].w)==mp.end())
                mp[a[i].w]=ans;
            else mp[a[i].w]=max(mp[a[i].w],ans);
        }
        for(int i=1;i<=q;i++){
            int num;
            cin>>num;
            auto pos=mp.lower_bound(num);
            if(pos!=mp.end()) printf("%lld\n",pos->second);
            else printf("%d\n",0);
        }
    }
    return 0;
}