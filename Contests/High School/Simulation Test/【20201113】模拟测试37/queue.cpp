#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
int n,m,last,ans=0x3f3f3f3f,maxx,minx;
int a[maxn],b[maxn],book[maxn*10],top;
map<int,int>pos;
struct node{
    int l,r,mn;
}tree[maxn*4];
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(tree[id].l==tree[id].r){
        if(l<=n)tree[id].mn=a[l];
        else tree[id].mn=0x3f3f3f3f;
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
    tree[id].mn=min(tree[id*2].mn,tree[id*2+1].mn);
}
void update(int id,int pos,int val)
{
    if(tree[id].l==tree[id].r){
        tree[id].mn=val;
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(pos<=mid)update(id*2,pos,val);
    else update(id*2+1,pos,val);
    tree[id].mn=min(tree[id*2].mn,tree[id*2+1].mn);
}
int query(int id,int l,int r)
{
    if(tree[id].l==l&&tree[id].r==r)return tree[id].mn;
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)return query(id*2,l,r);
    else if(l>mid)return query(id*2+1,l,r);
    else return min(query(id*2,l,mid),query(id*2+1,mid+1,r));
}
int main(){
    //freopen("queue.in","r",stdin);
    //freopen("queue.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    last=n;
    build(1,1,n+m+1);
    for(int i=1,x;i<=m;i++){
        char opt;
        scanf("\n%c %d",&opt,&x);
        if(opt=='A'){
            if(pos[x]<=1){
                puts("-1");
                continue;
            }
            int t=query(1,1,pos[x]-1);
            if(t==0x3f3f3f3f)puts("-1");
            else printf("%d\n",t);
        }else{
            update(1,pos[x],0x3f3f3f3f);
            update(1,++last,x);
            pos[x]=last;
        }
    }
    for(map<int,int>::iterator it=pos.begin();it!=pos.end();it++)
        b[++top]=it->second;
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        book[b[i]]=1;
    maxx=b[n],minx=b[1];
    for(int i=minx;i<=maxx;i++)
        book[i]+=book[i-1];
    for(int i=minx;i+n-1<=maxx;i++)
        ans=min(ans,n-(book[i+n-1]-book[i-1]));
    printf("%d",ans);
    return 0;
}
