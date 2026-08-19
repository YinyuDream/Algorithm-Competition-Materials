#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,cnt_edge,k;
int a[maxn],pos[maxn];
struct graph{
    int to,next,wt,id;
}edge[maxn];
int head[maxn];
void add_edge(int u,int v,int w,int id)
{
    edge[++cnt_edge].to=v;
    edge[cnt_edge].next=head[u];
    edge[cnt_edge].wt=w;
    edge[cnt_edge].id=id;
    head[u]=cnt_edge;
}
int deep[maxn],son[maxn],size[maxn],fa[maxn],top[maxn],tid[maxn],old[maxn];
void dfs1(int u,int f)
{
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=f)
        {
            deep[v]=deep[u]+1;
            fa[v]=u;
            a[v]=edge[i].wt;
            pos[edge[i].id]=v;
            dfs1(v,u);
            size[u]+=size[v];
            if(!son[u]||size[son[u]]<size[v])
            son[u]=v;
        }
    }
}
void dfs2(int u,int tp)
{
	top[u]=tp;
    tid[u]=++k;
    old[k]=u;
    if(!son[u])return ;
    dfs2(son[u],tp);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa[u]&&v!=son[u])
        dfs2(v,v);
    }
}
struct node{
    int l,r,add,lazy,mx;
}tree[maxn];
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(tree[id].l==tree[id].r){
        tree[id].mx=a[old[l]];
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
    tree[id].mx=max(tree[id*2].mx,tree[id*2+1].mx);
}
void pushdown(int id)
{
    if(tree[id].lazy)
    {
        tree[id*2].mx=tree[id].lazy;
        tree[id*2].lazy=tree[id].lazy;
        tree[id*2+1].mx=tree[id].lazy;
        tree[id*2+1].lazy=tree[id].lazy;
        tree[id].lazy=tree[id].add=0;
    }
    if(tree[id].add)
    {
        tree[id*2].mx+=tree[id].add;
        tree[id*2].add+=tree[id].add;
        tree[id*2+1].mx+=tree[id].add;
        tree[id*2+1].add+=tree[id].add;
        if(tree[id*2].lazy)tree[id*2].lazy+=tree[id].add;
        if(tree[id*2+1].lazy)tree[id*2+1].lazy+=tree[id].add;
        tree[id].add=0;
    }
}
void change(int id,int l,int r,int c)
{
    pushdown(id);
    if(tree[id].l==l&&tree[id].r==r){
        tree[id].lazy=c;
        tree[id].mx=c;
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)change(id*2,l,r,c);
    else if(l>mid)change(id*2+1,l,r,c);
    else change(id*2,l,mid,c),change(id*2+1,mid+1,r,c);
    tree[id].mx=max(tree[id*2].mx,tree[id*2+1].mx);
}
void update(int id,int l,int r,int c)
{
    pushdown(id);
    if(tree[id].l==l&&tree[id].r==r){
        tree[id].add+=c;
        if(tree[id].lazy)tree[id].lazy+=c;
        tree[id].mx+=c;
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)update(id*2,l,r,c);
    else if(l>mid)update(id*2+1,l,r,c);
    else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
    tree[id].mx=max(tree[id*2].mx,tree[id*2+1].mx);
}
int query(int id,int l,int r)
{
    if(tree[id].l==l&&tree[id].r==r)return tree[id].mx;
    pushdown(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)return query(id*2,l,r);
    else if(l>mid)return query(id*2+1,l,r);
    else return max(query(id*2,l,mid),query(id*2+1,mid+1,r));
}
void trim(int u,int v,int c)
{
    while(top[u]!=top[v])
    {
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        update(1,tid[top[u]],tid[u],c);
        u=fa[top[u]];
    }
    if(deep[u]>deep[v])swap(u,v);
    if(tid[u]<tid[v])update(1,tid[u]+1,tid[v],c);
}
void cover(int u,int v,int c)
{
    while(top[u]!=top[v])
    {
    	
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        change(1,tid[top[u]],tid[u],c);
        u=fa[top[u]];
    }
    if(deep[u]>deep[v])swap(u,v);
    if(tid[u]<tid[v])change(1,tid[u]+1,tid[v],c);
}
int find(int u,int v)
{
    int mx=0;
    while(top[u]!=top[v])
    {
        if(deep[top[u]]<deep[top[v]])swap(u,v);
        mx=max(mx,query(1,tid[top[u]],tid[u]));
        u=fa[top[u]];
    }
    if(deep[u]>deep[v])swap(u,v);
    if(tid[u]<tid[v])mx=max(mx,query(1,tid[u]+1,tid[v]));
    return mx;
}
int main(){
    scanf("%d",&n);
    for(int i=1,u,v,w;i<n;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w,i);
        add_edge(v,u,w,i);
    }
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,n);
    for(int i=1,u,v,w;i;i++)
    {
        string opt;
        cin>>opt;
        if(opt=="Change"){
            scanf("%d%d",&u,&w);
            change(1,tid[pos[u]],tid[pos[u]],w);
        }else if(opt=="Cover"){
            scanf("%d%d%d",&u,&v,&w);
            cover(u,v,w);
        }else if(opt=="Add"){
            scanf("%d%d%d",&u,&v,&w);
            trim(u,v,w);
        }else if(opt=="Max"){
            scanf("%d%d",&u,&v);
            printf("%d\n",find(u,v));
        }else break;
    }
    return 0;
}
