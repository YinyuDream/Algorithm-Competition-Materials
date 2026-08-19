#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
struct node{
    int to,next,wt;
};
void work()
{
    int n,cnt=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1),is_leaf(n+1);
    vector<double> mn(n+1),mx(n+1);
    auto add=[&](int u,int v,int w){
        edge[++cnt].to=v;
        edge[cnt].wt=w;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    function<void(int,int,int,int,double)> dfs=[&](int u,int fa,int cnt_1,int depth,double res){
        is_leaf[u]=true;
        double mn_=1e9,mx_=-1e9;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa) continue;
            is_leaf[u]=false;
            dfs(v,u,cnt_1+edge[i].wt,depth+1,min(res,1.0*(cnt_1+edge[i].wt)/(depth+1)));
            mn_=min(mn_,mn[v]);
            mx_=max(mx_,mx[v]);
        }
        if(is_leaf[u]){
            mn[u]=mx[u]=res;
            return ;
        }
        mn[u]=mn_;
        mx[u]=mx_;
    };
    function<double(int,int,int)> solve=[&](int u,int fa,int now){
        //cout<<u<<endl;
        if(is_leaf[u]) return mn[u];
        if(now==1){
            double res=-1e9;
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                if(v!=fa)
                    res=max(res,solve(v,u,0));
            }
            return res;
        }else{
            double res=1e9;
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                if(v!=fa)
                    res=min(res,solve(v,u,1));
            }
            return res;
        }
    };
    dfs(1,1,0,0,1);
    //for(int i=1;i<=n;i++)
    //   cout<<mx[i]<<" "<<mn[i]<<endl;
    cout<<fixed<<setprecision(10);
    cout<<solve(1,1,1)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}