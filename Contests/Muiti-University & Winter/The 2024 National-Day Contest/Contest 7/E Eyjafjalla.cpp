#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,next;
};
int main(){
    int n;
    cin>>n;
    vector<node> edge(n*2+1);
    vector<int> head(n+1);
    auto add=[&](int u,int v){
        static int cnt=0;
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    vector<int> t(n+1);
    for(int i=1;i<=n;i++)
        cin>>t[i];
    t[0]=1e9;
    vector<int> sz(n+1),dfn(n+1);
    int tot=0;
    vector<vector<int>> fa(n+1,vector<int>(15));
    function<void(int,int)> dfs=[&](int u,int f){
        for(int i=1;i<15;i++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
        sz[u]=1;
        dfn[u]=++tot;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v!=f){
                fa[v][0]=u;
                dfs(v,u);
                sz[u]+=sz[v];
            }
        }
    };
    dfs(1,0);
    int q;
    cin>>q;
    vector<int> ans(q+1);
    vector<tuple<int,int,int>> query;
    auto up=[&](int u,int lim){
        for(int i=14;i>=0;i--){
            while(t[fa[u][i]]<=lim){
                u=fa[u][i];
            }
        }
        return u;
    };
    for(int i=1;i<=q;i++){
        int x,l,r;
        cin>>x>>l>>r;
        if(t[x]<l||t[x]>r){
            ans[i]=0;
            continue;
        }else{
            query.push_back({i,up(x,r),l});
        }
    }
    sort(query.begin(),query.end(),[&](tuple<int,int,int> u,tuple<int,int,int> v){
        return get<2>(u)<get<2>(v);
    });
    vector<pair<int,int>> data(n+1);
    for(int i=1;i<=n;i++){
        data[i].first=i;
        data[i].second=t[i];
    }
    sort(data.begin()+1,data.end(),[&](pair<int,int> u,pair<int,int> v){
       return u.second<v.second; 
    });
    vector<int> c(n+1);
    auto update=[&](int x){
        for(int i=x;i<=n;i+=i&(-i)){
            c[i]++;
        }
    };
    auto ask=[&](int x){
        int ans=0;
        for(int i=x;i;i-=i&(-i)){
            ans+=c[i];
        }
        return ans;
    };
    for(int i=0,now=0;i<query.size();i++){
        auto [x,y,z]=query[i];;
        while(now<n&&data[now+1].second<z){
            update(dfn[data[++now].first]);
        }
        ans[x]=sz[y]-(ask(dfn[y]+sz[y]-1)-ask(dfn[y]-1));
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}