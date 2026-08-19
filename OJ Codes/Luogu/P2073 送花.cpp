#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
struct node{
    int l,r,sum,cost;
}tree[maxn*4];
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(tree[id].l==tree[id].r)return;
    int mid=(tree[id].l+tree[id].r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void add(int id,int x,int c)
{
    if(tree[id].l==x&&tree[id].r==x)
    {
        if(tree[id].sum==0)
        tree[id].sum+=c,
        tree[id].cost+=x;
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(x<=mid)add(id*2,x,c);
    else add(id*2+1,x,c);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].cost=tree[id*2].cost+tree[id*2+1].cost;
}
void del_min(int id)
{
    if(tree[id].l==tree[id].r){
        if(tree[id].sum)
        tree[id].sum=0,tree[id].cost=0;
        return ;
    }
    if(tree[id*2].sum)del_min(id*2);
    else if(tree[id*2+1].sum)del_min(id*2+1);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].cost=tree[id*2].cost+tree[id*2+1].cost;
}
void del_max(int id)
{
    if(tree[id].l==tree[id].r){
        if(tree[id].sum)
        tree[id].sum=0,tree[id].cost=0;
        return ;
    }
    if(tree[id*2+1].sum)del_max(id*2+1);
    else if(tree[id*2].sum)del_max(id*2);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].cost=tree[id*2].cost+tree[id*2+1].cost;
}
int main(){
    build(1,1,1000000);
    while(1)
    {
        int opt,w,c;
        scanf("%d",&opt);
        if(opt==1)scanf("%d%d",&w,&c),add(1,c,w);
        else if(opt==2)del_max(1);
        else if(opt==3)del_min(1);
        else return printf("%d %d",tree[1].sum,tree[1].cost),0;
    }
    return 0;
}
