#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f;
int n,m;
int a[maxn];
struct node{
    int _max,_min,size,l,r;
}tree[maxn*4];
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(l==r){
        tree[id]._min=tree[id]._max=a[l];
        tree[id].size=1;
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
    tree[id]._max=max(tree[id*2]._max,tree[id*2+1]._max);
    tree[id]._min=min(tree[id*2]._min,tree[id*2+1]._min);
    tree[id].size=tree[id*2].size+tree[id*2+1].size;
}
void update(int id,int x)
{
    if(tree[id].size==1){
        tree[id].size=0;
        tree[id]._min=inf;
        tree[id]._max=-inf;
        return ;
    }
    if(x<=tree[id*2].size)update(id*2,x);
    else update(id*2+1,x-tree[id*2].size);
    tree[id].size=tree[id*2].size+tree[id*2+1].size;
    tree[id]._max=max(tree[id*2]._max,tree[id*2+1]._max);
    tree[id]._min=min(tree[id*2]._min,tree[id*2+1]._min);
}
node query(int id,int l,int r)
{
    if(tree[id].size==r-l+1)return tree[id];
    if(r<=tree[id*2].size)return query(id*2,l,r);
    else if(l>tree[id*2].size)return query(id*2+1,l-tree[id*2].size,r-tree[id*2].size);
    else {
        node t1=query(id*2,l,tree[id*2].size),t2=query(id*2+1,1,r-tree[id*2].size),t3;
        t3._max=max(t1._max,t2._max),t3._min=min(t1._min,t2._min);
        return t3;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1,opt,x,y;i<=m;i++)
    {
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d",&x);
            update(1,x);
        }else{
            scanf("%d%d",&x,&y);
            node t=query(1,x,y);
            printf("%d %d\n",t._min,t._max);
        }
    }
    return 0;
}
