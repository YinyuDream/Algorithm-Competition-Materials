#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10,p=1e9+7;
int T,n,k;
int a[maxn],b[maxn],w[maxn],flag[maxn],book[maxn],dis[maxn],fa[maxn],fac[maxn],ans[maxn];
struct node{
    int to,next;
}edge[maxn];
int head[maxn];
int read(){
    int x=0;
    char ch=getchar();
    int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*=f;
}
int write(int x)
{
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int ksm(int u,int v){
    if(v==0)
        return 1;
    int ans=ksm(u,v/2);
    ans=1ll*ans*ans%p;
    if(v%2==1)
        ans=1ll*ans*u%p;
    return ans;
}
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void init()
{
    k=0;
    n=read();
    for(int i=1;i<=n;i++){
        head[i]=0;
        edge[i].to=0;
        edge[i].next=0;
        book[i]=0;
    }
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n;i++){
        b[i]=read();
        add(b[i],i);
    }
    for(int i=1;i<=n;i++)
        w[i]=read();
    for(int i=1;i<=n;i++){
        if(b[i]==i){
            flag[i]=2;
            continue;
        }
        if(a[b[i]]>a[i])
            flag[i]=1;
        else if(a[b[i]]+w[b[i]]<=a[i])
            flag[i]=2;
        else
            flag[i]=3;
    }
}
void dfs(int u)
{
    book[u]=1;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(!book[v]&&flag[v]==3){ 
            dis[v]=dis[u]+1;
            fa[v]=fa[u];
            dfs(v);
        }
    }
}
void work()
{
    for(int i=1;i<=n;i++){
        if(!book[i]&&(flag[i]==1||flag[i]==2)){
            fa[i]=i;
            dis[i]=1;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==1){
            ans[i]=(a[i]+w[i])%p;
        }else if(flag[i]==2){
            ans[i]=a[i];
        }else{
            if(book[i]&&flag[fa[i]]==1)
                ans[i]=(a[i]+1ll*w[i]*fac[dis[i]])%p;
            else
                ans[i]=a[i];
        }
    }
    for(int i=1;i<=n;i++)
        write(ans[i]),putchar(' ');
    puts("");
}
int main(){
    T=read();
    fac[0]=1;
    for(int i=1;i<maxn;i++){
        fac[i]=1ll*fac[i-1]*i%p;
    }
    for(int i=1;i<maxn;i++){
        fac[i]=ksm(fac[i],p-2)%p;
    }
    while(T--){
        init();
        work();
    }
    return 0;
}