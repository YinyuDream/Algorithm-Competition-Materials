#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10,inf=0x7f7f7f7f;
int n,m;
int a[maxn];
struct node{
    int l,r,lazy_a,lazy_d,num,flag;
}tree[maxn*4];
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(tree[id].l==tree[id].r){
        tree[id].num=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void pushdown(int id)
{
    tree[id*2].flag=tree[id*2+1].flag=1;
    tree[id*2].lazy_a+=tree[id].lazy_a;
    tree[id*2].lazy_d+=tree[id].lazy_d;
    tree[id*2+1].lazy_a+=tree[id].lazy_a+(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy_d;
    tree[id*2+1].lazy_d+=tree[id].lazy_d;
    if(tree[id*2].l==tree[id*2].r)tree[id*2].num+=tree[id].lazy_a;
    if(tree[id*2+1].l==tree[id*2+1].r)tree[id*2+1].num+=tree[id].lazy_a+(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy_d;
    tree[id].lazy_a=tree[id].lazy_d=tree[id].flag=0;
}
void update(int id,int l,int r,int _a,int _d)
{
    if(tree[id].l==l&&tree[id].r==r){
        tree[id].flag=1;
        tree[id].lazy_a+=_a,tree[id].lazy_d+=_d;
        if(tree[id].l==tree[id].r)tree[id].num+=_a;
        return ;
    }
    if(tree[id].flag)pushdown(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)update(id*2,l,r,_a,_d);
    else if(l>mid)update(id*2+1,l,r,_a,_d);
    else update(id*2,l,mid,_a,_d),update(id*2+1,mid+1,r,_a+(mid-l+1)*_d,_d);
}
int query(int id,int x)
{
    if(tree[id].l==x&&tree[id].r==x)
    return tree[id].num;
    if(tree[id].flag)pushdown(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(x<=mid)return query(id*2,x);
    else return query(id*2+1,x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1,opt,l,r,k,d;i<=m;i++)
    {
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d%d%d",&l,&r,&k,&d);
            update(1,l,r,k,d);
        }else{
            scanf("%d",&k);
            printf("%d\n",query(1,k));
        }
    }
    return 0;
}
