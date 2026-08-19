#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
int n,m,cnt;
ll w[maxn],sum[maxn];
struct node{
    int to,next;
}edge[maxn];
int fa[maxn],head[maxn],book[maxn];
bool is_in[maxn],is_child[maxn];
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void cal(int u)
{
    sum[u]=w[u];
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(book[v])continue;
        if(!sum[v])cal(v);
        sum[u]+=sum[v];
    }
}
void sum_to_abs(){
    ll all=0;
    for(int i=1;i<=n;i++)
        if(!book[i])
            all+=w[i];
    for(int i=1;i<=n;i++)
        if(!book[i])
            sum[i]=abs(sum[i]-(all-sum[i]));
}
void is_in_child(int u)
{
    while(u){
        is_in[u]=1;
        u=fa[u];
    }
}
void check_child(int u)
{
    is_child[u]=1;
    for(int i=head[u];i;i=edge[i].next)
        check_child(edge[i].to);
}
void work(int val)
{
    memset(book,0,sizeof(book));
    memset(is_in,0,sizeof(is_in));
    is_in_child(val);
    int cnt=n;
    while(cnt>1){
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
            if(!sum[i])
                cal(i);
        sum_to_abs();
        int mxp=0;
        ll mx=1e12;
        for(int i=n;i;i--){
            if(!book[i]&&sum[i]<=mx){
                mx=sum[i];
                mxp=i;
            }
        }
        memset(is_child,0,sizeof(is_child));
        check_child(mxp);
        if(!is_in[mxp]){
            for(int i=1;i<=n;i++)
                if(is_child[i])
                    book[i]=1;
        }else{
            for(int i=1;i<=n;i++)
                if(!is_child[i])
                    book[i]=1;
        }
        cnt=0;
        for(int i=1;i<=n;i++)
            if(book[i]==0)
                cnt++;
        cout<<mxp<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        add(fa[i],i);
    }
    for(int i=1,val;i<=m;i++){
        cin>>val;
        work(val);
    }
    return 0;
}