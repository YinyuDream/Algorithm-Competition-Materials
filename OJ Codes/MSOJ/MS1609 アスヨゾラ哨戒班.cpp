#pragma GCC optimize(3)
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int n,m,cnt;
int p[maxn],minx[maxn],maxx[maxn],num[maxn],help[maxn],news[maxn],a[maxn],delta[maxn],is_big[maxn];
struct node{
    int l,r,mx[27],num[27];
    ll sum[27];
    node(){
        l=r=0;
        memset(mx,0,sizeof mx);
        memset(num,0,sizeof num);
        memset(sum,0,sizeof sum);
    }
}tree[maxn*4];
void lsh()
{
    for(int i=1;i<=n;i++)
        help[i]=p[i];
    sort(help+1,help+n+1);
    cnt=unique(help+1,help+n+1)-help-1;
    for(int i=1;i<=n;i++)
        news[i]=lower_bound(help+1,help+cnt+1,p[i])-help;
}
void pushup(int id)
{
    for(int i=0;i<=26;i++){
        tree[id].mx[i]=max(tree[id*2].mx[i],tree[id*2+1].mx[i]);
        tree[id].sum[i]=tree[id*2].sum[i]+tree[id*2+1].sum[i];
        tree[id].num[i]=tree[id*2].num[i]+tree[id*2+1].num[i];
    }
}
void build(int id,int l,int r)
{
    tree[id].l=l,tree[id].r=r;
    if(l==r)return ;
    int mid=(l+r)/2;
    build(id*2,l,mid),build(id*2+1,mid+1,r);
}
void update(int id,int pos)
{
	if(tree[id].l==tree[id].r){
		tree[id].mx[is_big[pos]*13+delta[pos]]=max(tree[id].mx[is_big[pos]*13+delta[pos]],a[pos]);
        tree[id].sum[is_big[pos]*13+delta[pos]]+=a[pos];
        tree[id].num[is_big[pos]*13+delta[pos]]++;
        return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(pos<=mid)update(id*2,pos);
	else update(id*2+1,pos);
	pushup(id);
}
node query(int id,int l,int r)
{
    if(tree[id].l==l&&tree[id].r==r)return tree[id];
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)return query(id*2,l,r);
    else if(l>mid)return query(id*2+1,l,r);
    else{
        node t1=query(id*2,l,mid),t2=query(id*2+1,mid+1,r),t3;
        for(int i=0;i<=26;i++){
            t3.mx[i]=max(t1.mx[i],t2.mx[i]);
            t3.sum[i]=t1.sum[i]+t2.sum[i];
            t3.num[i]=t1.num[i]+t2.num[i];
        }
        return t3;
    }
}
ll work(int opt,int l,int r,int t)
{
    l=lower_bound(help+1,help+cnt+1,l)-help;
    r=upper_bound(help+1,help+cnt+1,r)-help-1;
    if(l>r)return -1;
    node _t=query(1,l,r);
    if(opt==0){
        ll ans=0;
        for(int i=1;i<=13;i++)
            ans+=_t.sum[i]+_t.num[i]*abs((t+i)%(2*i)-i);
        for(int i=1;i<=13;i++)
            ans+=_t.sum[i+13]-_t.num[i+13]*abs((t+i)%(2*i)-i);
        ans+=_t.sum[0];
        return ans;
    }else{
        int mx=0;
        for(int i=1;i<=13;i++)
            mx=max(mx,_t.mx[i]+abs((t+i)%(2*i)-i));
        for(int i=1;i<=13;i++)
            mx=max(mx,_t.mx[i+13]-abs((t+i)%(2*i)-i));
        mx=max(mx,_t.mx[0]);
        return 1ll*mx;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&p[i],&minx[i],&maxx[i],&num[i]);
    lsh();
    build(1,1,n);
    for(int i=1;i<=n;i++){
        a[news[i]]=num[i]?maxx[i]:minx[i];
        delta[news[i]]=maxx[i]-minx[i];
        if(delta[news[i]])is_big[news[i]]=num[i];
        else is_big[news[i]]=0;
        update(1,news[i]);
    }
    for(int i=1,opt,t,l,r;i<=m;i++){
        scanf("%d%d%d%d",&opt,&t,&l,&r);
        printf("%lld\n",work(opt,l,r,t));
    }
    return 0;
}