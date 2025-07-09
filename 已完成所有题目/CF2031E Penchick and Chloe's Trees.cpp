#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n;
    cin>>n;
    vector<node> edge(n+1);
    vector<int> head(n+1);
    int cnt_edge=0;
    auto addedge=[&](int u,int v){
        edge[++cnt_edge].to=v;
        edge[cnt_edge].next=head[u];
        head[u]=cnt_edge;
    };
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        addedge(x,i);
    }
    vector<int> f(n+1);
    function<void(int)> solve=[&](int u){
        if(!head[u]){
            f[u]=1;
            return;
        }
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            solve(v);
        }
        if(edge[head[u]].next==0){
            f[u]=f[edge[head[u]].to]+1;
            return;
        }
        multiset<int> res;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            res.insert(f[v]);
        }
        while(res.size()>2){
            auto it=res.begin();
            int x=*it;
            res.erase(it);
            auto it2=res.begin();
            int y=*it2;
            res.erase(it2);
            res.insert((max(x,y)+1));
        }
        f[u]=*res.rbegin()+1;
    };
    solve(1);
    cout<<f[1]-1<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}