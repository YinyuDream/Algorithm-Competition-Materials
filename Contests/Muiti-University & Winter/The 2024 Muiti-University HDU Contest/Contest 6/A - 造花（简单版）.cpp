#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n,cnt=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1),in(n+1),f(n+1);
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
        in[u]++;
        in[v]++;
    }
    function <void(int,int,vector<int>&)> dfs=[&](int u,int fa,vector<int> &dis){
        int res=0;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa) continue;
            dis[v]=dis[u]+1;
            f[v]=u;
            dfs(v,u,dis);
        }
    };
    auto mid_point=[&](){
        vector<int> dis(n+1);
        dfs(1,0,dis);
        int mxpos=max_element(dis.begin()+1,dis.end())-dis.begin();
        dis=vector<int>(n+1);
        dfs(mxpos,0,dis);
        mxpos=max_element(dis.begin()+1,dis.end())-dis.begin();
        int mxdis=dis[mxpos];
        while(dis[mxpos]>mxdis/2+1){
            mxpos=f[mxpos];
        }
        return make_pair(mxpos,f[mxpos]);
    };
    pair<int,int> p=mid_point();
    auto can=[&](int mid){
        if(in[mid]!=2){
            return false;
        }
        int u=edge[head[mid]].to,v=edge[edge[head[mid]].next].to;
        auto check=[&](int x){
            if(in[x]==2){
                int pre=x;
                for(int i=head[x];i;i=edge[i].next){
                    int y=edge[i].to;
                    if(y!=mid){
                        x=y;
                        break;
                    }
                }
                for(int i=head[x];i;i=edge[i].next){
                    int y=edge[i].to;
                    if(y!=pre){
                        if(in[y]>1){
                            return false;
                        }
                    }
                }
                return true;
            }else{
                for(int i=head[x];i;i=edge[i].next){
                    int y=edge[i].to;
                    if(y==mid) continue;
                    if(in[y]>1){
                        return false;
                    }
                }
                return true;
            }
        };
        return check(u)&&check(v);
    };
    if(can(p.first)||can(p.second)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}