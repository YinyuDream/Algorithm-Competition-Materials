#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int mod=998244353;
struct node{
    int to,next;
};
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll inv(ll x){
    return ksm(x,mod-2);
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),pos(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    vector<node> edge(2*n+1);
    vector<int> head(n+1),father(n+1),ancestor(n+1),ban(n+1);
    vector<ll> f(n+1,1);
    int cnt=0;
    auto add_edge=[&](int u,int v){
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    function<void(int,int)> dfs=[&](int u,int fa){
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa) continue;
            father[v]=u;
            ancestor[v]=u;
            dfs(v,u);
            f[u]=(f[u]*(f[v]+1))%mod;
        }
    };
    dfs(pos[0],0);
    ll ans=f[pos[0]],tot=0;
    ancestor[pos[0]]=pos[0];
    ban[pos[0]]=1;
    for(int i=1;i<n;i++){//mex=i
        int u=pos[i];
        if(ban[u]){
            continue;
        }
        ll val=0;
        while(!ban[ancestor[u]]){
            int tmp=u;
            u=ancestor[u];
            ll tmp_val=f[u];
            tmp_val=(tmp_val*inv(f[tmp]+1))%mod;
            tmp_val=(tmp_val*(val+1))%mod;
            val=tmp_val;
        }
        ll __ans=ans;
        __ans=(__ans*inv(f[u]+1))%mod;
        __ans=(__ans*(val+1))%mod;
        tot=(tot+i*__ans)%mod;
        u=pos[i];
        for(int j=head[u];j;j=edge[j].next){
            int v=edge[j].to;
            if(v==father[u]){
                continue;
            }
            ancestor[v]=pos[0];
            ans=(ans*(f[v]+1))%mod;
        }
        while(!ban[ancestor[u]]){
            int tmp=u;
            u=ancestor[u];
            for(int j=head[u];j;j=edge[j].next){
                int v=edge[j].to;
                if(v==tmp||v==father[u]){
                    continue;
                }
                ancestor[v]=pos[0];
                ans=(ans*(f[v]+1))%mod;
            }
            ancestor[tmp]=pos[0];
            ban[tmp]=1;
        }
        ban[u]=1;
        ancestor[u]=pos[0];
        ans=(ans*inv(f[u]+1))%mod;
    }
    cout<<(tot+n)%mod<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}