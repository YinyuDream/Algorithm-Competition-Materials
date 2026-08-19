#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+10;
int T,n,m,s,t,cnt,tot;
struct node{
    int to,next,wt;
}edge[maxn];
int head[maxn],fa[maxn];
unordered_map<ll,int>mp;
vector<int>vec[maxn];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int trans(int id,int col)
{
    ll val=1ll*id*maxn+col;
    if(mp.find(val)==mp.end()){
        mp.insert(make_pair(val,++tot));
        return tot;
    }else{
        return mp[val];
    }
}
void add(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].wt=w;
    head[u]=cnt;
}
int book[maxn];
void bfs()
{
    if(s==t){
        cout<<0<<endl;
        return;
    }
    deque<pair<int,int>>q;
    int ans=0;
    q.push_back({trans(s,0),1});
    while(!q.empty()){
        auto u=q.front();
        q.pop_front();
        book[u.first]=1;
        if(u.first==trans(t,0)){
            ans=u.second;
            break;
        }
        for(int i=head[u.first];i;i=edge[i].next){
            int v=edge[i].to;
            if(book[v])continue;
            if(edge[i].wt==0)q.push_front({v,u.second});
            else q.push_back({v,u.second+1});
            book[v]=1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;i++)
            fa[i]=i;
        for(int i=1;i<=m;i++){
            int u,v,w;
            u=read();v=read();w=read();
            add(trans(u,w),trans(v,w),0);
            add(trans(v,w),trans(u,w),0);
            vec[u].push_back(w);
            vec[v].push_back(w);
        }
        s=read();t=read();
        for(int i=1;i<=n;i++){
            if(vec[i].empty())
                continue;
            for(int j=0;j<vec[i].size();j++){
                if(i!=t){
                    add(trans(i,vec[i][j]),trans(i,0),1);
                }else{
                    add(trans(i,vec[i][j]),trans(i,0),0);
                }
                add(trans(i,0),trans(i,vec[i][j]),0);
            }
        }
        bfs();
        for(int i=1;i<=cnt;i++)
            edge[i].to=edge[i].next=edge[i].wt=0;
        for(int i=1;i<=n;i++)
            vec[i].clear(),fa[i]=0;
        for(int i=1;i<=tot;i++)
            book[i]=head[i]=0;
        mp.clear();
        cnt=tot=0;
    }
    return 0;
}