#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m;
int in[maxn],in_unused[maxn],dis[maxn],ans[maxn],out[maxn];
vector<int>v[maxn];
vector<int>edge[maxn];
set<int>st[maxn];
void init()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        v[i].clear();
    for(int i=0;i<=n;i++){
        edge[i].clear();
        st[i].clear();
        in[i]=dis[i]=ans[i]=0;
    }
    for(int i=1,num;i<=n;i++){
        cin>>num;
        for(int j=1,u;j<=num;j++){
            cin>>u;
            v[u].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=m;i++){
        for(auto j=v[i].begin();j!=v[i].end();j++){
            if(j==v[i].end()-1)
                break;
            if(st[*j].count(*(v[i].end()-1))==0){
                edge[*j].push_back(*(v[i].end()-1));
                st[*j].insert(*(v[i].end()-1));
                in[*(v[i].end()-1)]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            edge[0].push_back(i);
            in[i]++;
        }
        in_unused[i]=in[i];
    }
    /*for(int i=0;i<=n;i++,puts("")){
        cout<<i<<": ";
        for(auto j:edge[i])
            cout<<j<<' ';
    }*/
}
bool bfs()
{
    for(int i=1;i<=n;i++)
        in[i]=in_unused[i];
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto i:edge[u]){
            in[i]--;
            dis[i]=max(dis[i],dis[u]+1);
            if(in[i]==0)
                q.push(i);
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,dis[i]);
    if(mx==n)
        return false;
    else
        return true;
}
bool check()
{
    for(int i=1;i<=n;i++){
        if(out[i]!=i)
            return true;
    }
    return false;
}
void solve(){
    for(int i=1;i<=n;i++)
        in[i]=in_unused[i];
    int now=0;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto i:edge[u]){
            in[i]--;
            if(in[i]==0){
                q.push(i);
                ans[i]=++now;
            }
        }
    }
    for(int i=1;i<=n;i++)
        out[ans[i]]=i;
}
void output()
{
    for(int i=1;i<n;i++)
        cout<<out[i]<<' ';
    cout<<out[n]<<endl;
}
void work()
{
    if(!bfs()){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        solve();
        while(!check()){
            for(int i=0;i<=n;i++)
                if(edge[i].size()>=2)
                    random_shuffle(edge[i].begin(),edge[i].end());
            solve();
        }
        output();
    }
    
}
int main(){
    srand(unsigned(time(0)));
    cin>>T;
    while(T--){
        init();
        work();
    }
    return 0;
}