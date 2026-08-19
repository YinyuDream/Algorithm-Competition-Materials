#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int to,next;
    ll wt;
};
class segment_tree{
    private:
    struct node{
        int l,r;
        ll max;
    };
    vector<node> tree;
    public:
    segment_tree(int n){
        tree.resize(4*n+10);
    };
    void build(int id,int l,int r){
        tree[id].l=l,tree[id].r=r;
        if(l==r){
            tree[id].max=0;
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
    }
    void update(int id,int pos,ll val){
        if(tree[id].l==tree[id].r){
            tree[id].max=val;
            return;
        }
        int mid=(tree[id].l+tree[id].r)/2;
        if(pos<=mid){
            update(id*2,pos,val);
        }else{
            update(id*2+1,pos,val);
        }
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
    }
    ll query(int id,int l,int r){
        if(l<=tree[id].l&&r>=tree[id].r){
            return tree[id].max;
        }
        int mid=(tree[id].l+tree[id].r)/2;
        if(r<=mid){
            return query(id*2,l,r);
        }else if(l>mid){
            return query(id*2+1,l,r);
        }else{
            return max(query(id*2,l,r),query(id*2+1,l,r));
        }
    }
};
int main(){
    int n;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1);
    auto add=[&](int u,int v,ll w){
        static int cnt=0;
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        edge[cnt].wt=w;
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    vector<int> dfn(n+1),dep(n+1),sz(n+1);
    vector<ll> sum(n+1);
    int tot=0;
    function<void(int,int)> dfs=[&](int u,int f){
        dfn[u]=++tot;
        sz[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v!=f){
                dep[v]=dep[u]+1;
                sum[v]=sum[u]+edge[i].wt;
                dfs(v,u);
                sz[u]+=sz[v];
            }
        }
    };
    dfs(1,0);
    int q;
    cin>>q;
    vector<tuple<int,int,int>> query(q);
    for(int i=0;i<q;i++){
        cin>>get<0>(query[i])>>get<1>(query[i]);
        get<2>(query[i])=i;
    }
    sort(query.begin(),query.end(),[&](tuple<int,int,int> u,tuple<int,int,int> v){
        return dep[get<0>(u)]+get<1>(u)<dep[get<0>(v)]+get<1>(v);
    });
    vector<vector<int>> points(n+1);
    vector<ll> ans(q);
    for(int i=1;i<=n;i++){
        points[dep[i]].push_back(i);
    }
    int now_dep=0;
    segment_tree tree(n);
    tree.build(1,1,n);
    for(auto [u,d,eth]:query){
        int new_dep=dep[u]+d;
        if(new_dep>n){
            ans[eth]=-1;
            continue;
        }
        if(new_dep!=now_dep){
            for(auto x:points[now_dep]){
                tree.update(1,dfn[x],0);
            }
            for(auto x:points[new_dep]){
                tree.update(1,dfn[x],sum[x]);
            }
            now_dep=new_dep;
        }
        ll mx=tree.query(1,dfn[u],dfn[u]+sz[u]-1);
        if(mx==0){
            ans[eth]=-1;
        }else{
            ans[eth]=mx-sum[u];
        }
    }
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}