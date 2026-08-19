#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct node{
    int to,next,wt;
}edge[maxn];
int head[maxn],in[maxn],fa[maxn],cnt;
void add(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].wt=w;
    head[u]=cnt;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)
        fa[x]=y;
}
 
void solve()
{
    int n, a, b;
    string s,t;
    cin>>n>>a>>b>>t;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    s=' '+t;
    while(s.size()<=4*a+5)
        s.append(t.begin(),t.end());
    vector<int> r(n+1);
    int cnt_0=0,cnt_1=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='0')
            cnt_0++;
        else
            cnt_1++;
        if(cnt_0==a||cnt_1==a){
            r[1]=i+1;
            r[1]=(r[1]-1)%n+1;
            add(1,r[1],cnt_0==a?0:1);
            in[r[1]]++;
            merge(1,r[1]);
            break;
        }
    }
    int mx=r[1]-1;
    for(int i=2;i<=n;i++){
        if(s[i-1]=='0')
            cnt_0--;
        else
            cnt_1--;
        while(cnt_0<a&&cnt_1<a){
            mx++;
            if(s[mx]=='0')
                cnt_0++;
            else
                cnt_1++;
        }
        r[i]=mx%n+1;
        add(i,r[i],cnt_0==a?0:1);
        merge(i,r[i]);
        in[r[i]]++;
    }
    vector<int>ans(n+1,-1),book(n+1);
    auto work=[&](int u){
        int now=u;
        int cnt_0=0,cnt_1=0;
        while(cnt_0<b&&cnt_1<b){
            if(edge[head[now]].wt==0)
                cnt_0++;
            else
                cnt_1++;
            now=edge[head[now]].to;
        }
        ans[u]=cnt_0==b?0:1;
        while(ans[edge[head[u]].to]==-1){
            if(edge[head[u]].wt==0)
                cnt_0--;
            else
                cnt_1--;
            u=edge[head[u]].to;
            while(cnt_0<b&&cnt_1<b){
                if(edge[head[now]].wt==0)
                    cnt_0++;
                else
                    cnt_1++;
                now=edge[head[now]].to;
            }
            ans[u]=cnt_0==b?0:1;
        }
        int root=edge[head[u]].to;
    };
 
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            work(i),book[find(i)]=1;
    for(int i=1;i<=n;i++)
        if(ans[i]==-1)
            work(i);
    for(int i=1;i<=n;i++)
        cout<<ans[i];
}
int main(){
    solve();
    return 0;
}