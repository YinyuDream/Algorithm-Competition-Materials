#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n,m,q,tot;
char s[maxn][maxn];
struct point{
    int x,y,pos,dir;
};
struct node{
    int to,next,wt;
}edge[maxn*maxn];
int head[maxn*maxn],in[maxn*maxn];
int coord(point u){
    int pos=u.pos,dir=u.dir,x=u.x,y=u.y;
    dir=(dir+1)/2;
    int val=pos*2+dir;
    return x*(m+1)+y+val*(n+1)*(m+1);
}
void add(point _u,point _v,int w){
    int u=coord(_u),v=coord(_v);
    edge[++tot].to=v;
    edge[tot].next=head[u];
    edge[tot].wt=w;
    head[u]=tot;
}
unordered_set<int>st,e_set;
stack<int>stk;
int vis[maxn*maxn],cnt[maxn*maxn];
bool dfs(int u)
{
    vis[u]=1;
    cnt[u]=e_set.size()-e_set.count(-1);
    stk.push(u);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(vis[v]){
            e_set.insert(edge[i].wt);
            cnt[u]=e_set.size()-e_set.count(-1);
            while(stk.size()){
                int x=stk.top();
                stk.pop();
                cnt[x]=cnt[u];
            }
            return true;
        }
        e_set.insert(edge[i].wt);
        if(dfs(v)) return true;
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch=getchar();
            while(ch!='-'&&ch!='|'&&ch!='/'&&ch!='\\')
                ch=getchar();
            s[i][j]=ch;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='-'){
                point u,v;
                u.x=i-1,u.y=j,u.pos=0,u.dir=1;
                v.x=i-1,v.y=j,v.pos=0,v.dir=-1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=0,u.dir=-1;
                v.x=i,v.y=j,v.pos=0,v.dir=1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j-1,u.pos=1,u.dir=1;
                v.x=i,v.y=j,v.pos=1,v.dir=1;
                add(v,u,-1);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=1,u.dir=-1;
                v.x=i,v.y=j-1,v.pos=1,v.dir=-1;
                add(v,u,-1);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
            }else if(s[i][j]=='|'){
                point u,v;
                u.x=i,u.y=j-1,u.pos=1,u.dir=1;
                v.x=i,v.y=j-1,v.pos=1,v.dir=-1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=1,u.dir=-1;
                v.x=i,v.y=j,v.pos=1,v.dir=1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i-1,u.y=j,u.pos=0,u.dir=1;
                v.x=i,v.y=j,v.pos=0,v.dir=1;
                add(v,u,-1);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=0,u.dir=-1;
                v.x=i-1,v.y=j,v.pos=0,v.dir=-1;
                add(v,u,-1);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
            }else if(s[i][j]=='/'){
                point u,v;
                u.x=i-1,u.y=j,u.pos=0,u.dir=1;
                v.x=i,v.y=j-1,v.pos=1,v.dir=-1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j-1,u.pos=1,u.dir=1;
                v.x=i-1,v.y=j,v.pos=0,v.dir=-1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=0,u.dir=-1;
                v.x=i,v.y=j,v.pos=1,v.dir=1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=1,u.dir=-1;
                v.x=i,v.y=j,v.pos=0,v.dir=1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
            }else{
                point u,v;
                u.x=i,u.y=j-1,u.pos=1,u.dir=1;
                v.x=i,v.y=j,v.pos=0,v.dir=1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=0,u.dir=-1;
                v.x=i,v.y=j-1,v.pos=1,v.dir=-1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i-1,u.y=j,u.pos=0,u.dir=1;
                v.x=i,v.y=j,v.pos=1,v.dir=1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
                u.x=i,u.y=j,u.pos=1,u.dir=-1;
                v.x=i-1,v.y=j,v.pos=0,v.dir=-1;
                add(v,u,m*(i-1)+j);
                in[coord(u)]++;
                st.insert(coord(u)),st.insert(coord(v));
            }
        }
    }
    for(auto i:st){
        if(!in[i]){
            while(stk.size())stk.pop();
            e_set.clear();
            dfs(i);
        }
    }
    for(auto i:st){
        
        if(!vis[i]){
            while(stk.size())stk.pop();
            e_set.clear();
            dfs(i);
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y;
        string s;
        cin>>x>>y>>s;
        point u;
        u.x=x,u.y=y;
        if(s=="above")
            u.pos=0,u.dir=-1,u.x--;
        else if(s=="below")
            u.pos=0,u.dir=1;
        else if(s=="left")
            u.pos=1,u.dir=-1,u.y--;
        else
            u.pos=1,u.dir=1;
        cout<<cnt[coord(u)]<<endl;
    }
    return 0;
}