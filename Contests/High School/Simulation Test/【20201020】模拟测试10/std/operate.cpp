#include<cstdio>
#define maxn 1000010
#define ll long long
#define lson t<<1
#define rs t<<1|1
#define mid ((l+r)>>1)
using namespace std;
struct nod{ll to,next;}e[maxn*2];
struct node{ll size,del,sum,tag;}tr[maxn*4];
struct no{ll opt,id,y;}q[maxn*2];
ll n,m,cnt,tot,tn,a[maxn],tid[maxn],pos[maxn],size[maxn],head[maxn];
void adde(ll from,ll to){
    e[++tot].to=to;
    e[tot].next=head[from];
    head[from]=tot;
}
void dfs(ll x,ll fat){
    tid[x]=++cnt;pos[cnt]=x;
    size[x]=1;
    for(ll i=head[x];i;i=e[i].next){
        ll v=e[i].to;
        if(v==fat) continue;
        dfs(v,x);
        size[x]+=size[v];
    }
}
void pushup(ll t){
    tr[t].sum=tr[lson].sum+tr[rs].sum;
    tr[t].size=tr[lson].size+tr[rs].size;;
}
void down(ll t){
    if(tr[t].tag){
        ll p=tr[t].tag;
        tr[t].tag=0;
        if(tr[lson].size) tr[lson].tag+=p;
        tr[lson].sum+=tr[lson].size*p;
        if(tr[rs].size) tr[rs].tag+=p;
        tr[rs].sum+=tr[rs].size*p;
    }
}
void build(ll t,ll l,ll r){
    if(l==r){
        if(pos[l]<=tn) tr[t].size=1;
        tr[t].sum=a[pos[l]];
        return;
    }
    build(lson,l,mid);
    build(rs,mid+1,r);
    pushup(t);
}
void update(ll t,ll l,ll r,ll a,ll b,ll data,ll tag){
    if(tr[t].del) return;
    if(l==a && r==b){
        if(!tag)tr[t].sum+=(ll)tr[t].size*data,tr[t].tag+=data;
        if(tag==-1) tr[t].size=tr[t].sum=tr[t].tag=0,tr[t].del=1;
        if(tag==1) tr[t].size=1,tr[t].sum=data;
        return;
    }
    down(t);
    if(b<=mid) update(lson,l,mid,a,b,data,tag);
    else if(a>mid) update(rs,mid+1,r,a,b,data,tag);
    else update(lson,l,mid,a,mid,data,tag),update(rs,mid+1,r,mid+1,b,data,tag);
    pushup(t);
}
ll lng(ll t,ll l,ll r,ll a,ll b){
    if(tr[t].del) return 0;
    if(l==a && r==b) return tr[t].size;
    down(t);
    if(b<=mid) return lng(lson,l,mid,a,b);
    else if(a>mid) return lng(rs,mid+1,r,a,b);
    else return lng(lson,l,mid,a,mid)+lng(rs,mid+1,r,mid+1,b);
}
ll query(ll t,ll l,ll r,ll a,ll b){
    if(tr[t].del) return 0;
    if(l==a && r==b) return tr[t].sum;
    down(t);
    if(b<=mid) return query(lson,l,mid,a,b);
    else if(a>mid) return query(rs,mid+1,r,a,b);
    else return query(lson,l,mid,a,mid)+query(rs,mid+1,r,mid+1,b);
}
signed main(){
    scanf("%lld",&n);tn=n;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1,u,v;i<=n-1;i++){
        scanf("%lld%lld",&u,&v);
        adde(u,v);adde(v,u);
    }
    scanf("%lld",&m);
    for(ll i=1,opt;i<=m;i++){
        scanf("%lld",&opt);
        if(opt==1) q[i].opt=1,scanf("%lld%lld",&q[i].id,&q[i].y),adde(q[i].id,++n),adde(n,q[i].id),q[i].id=n;
        if(opt==2) q[i].opt=2,scanf("%lld",&q[i].id);
        if(opt==3) q[i].opt=3,scanf("%lld%lld",&q[i].id,&q[i].y);
        if(opt==4) q[i].opt=4,scanf("%lld",&q[i].id);
    }
    dfs(1,0);
    build(1,1,n);
    for(ll i=1;i<=m;i++){
        if(q[i].opt==1) update(1,1,n,tid[q[i].id],tid[q[i].id],q[i].y,1);
        if(q[i].opt==2) update(1,1,n,tid[q[i].id],tid[q[i].id]+size[q[i].id]-1,0,-1);
        if(q[i].opt==3) update(1,1,n,tid[q[i].id],tid[q[i].id]+size[q[i].id]-1,q[i].y,0);
        if(q[i].opt==4){
            if(!lng(1,1,n,tid[q[i].id],tid[q[i].id]+size[q[i].id]-1)) continue;
            ll ans=query(1,1,n,tid[q[i].id],tid[q[i].id]+size[q[i].id]-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}










#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=301000;
const int inf=0x7f7f7f7f;
struct st{
    int opt,x,y;
}Ask[maxn];
int n,m,head[maxn],k,f[maxn],N;
struct ss{
    int next,to;
}e[maxn*2];
void build(int a,int b)
{
    e[++k].next=head[a];
    e[k].to=b;head[a]=k;
}
int deep[maxn],fa[maxn],size[maxn],son[maxn];
void dfs1(int x,int pre)
{
    fa[x]=pre;
    size[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==pre) continue;
        deep[v]=deep[x]+1;
        dfs1(v,x);
        size[x]+=size[v];
        if(!son[x]||size[son[x]]<size[v]) son[x]=v;
    }
}
int top[maxn],tid[maxn],pos[maxn],cnt;
void dfs2(int x,int tp)
{
    top[x]=tp;
    pos[x]=++cnt;
    tid[cnt]=x;
    if(!son[x]) return;
    dfs2(son[x],tp);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x]||v==son[x]) continue;
        dfs2(v,v);
    }
}
struct tt{
    int sum,l,r,add,del,tru;
}tr[maxn*4];
void update(int x)
{
    tr[x].sum=tr[x*2].sum+tr[x*2+1].sum;
    tr[x].tru=tr[x*2].tru+tr[x*2+1].tru;
}
void build_tr(int x,int l,int r)
{
    tr[x].l=l,tr[x].r=r;
    tr[x].add=tr[x].del=0;
    tr[x].tru=0;
    if(l==r)
    {
        tr[x].sum=f[tid[l]];
        if(tid[l]<=N) tr[x].tru=1;
        return;
    }
    int mid=(l+r)/2;
    build_tr(x*2,l,mid);
    build_tr(x*2+1,mid+1,r);
    update(x);
}
void down(int x)
{
    if(!tr[x*2].del)
    {
        tr[x*2].add+=tr[x].add;
        tr[x*2].sum+=tr[x*2].tru*tr[x].add;
    }
    if(!tr[x*2+1].del)
    {
        tr[x*2+1].add+=tr[x].add;
        tr[x*2+1].sum+=tr[x*2+1].tru*tr[x].add;
    }
    tr[x].add=0;
}
void change(int x,int l,int r,int v)
{
    if(tr[x].l>r||tr[x].r<l) return;
    if(tr[x].del) return;
    if(l<=tr[x].l&&tr[x].r<=r)
    {
        if(v==-inf)
        {
            tr[x].del=1,tr[x].sum=0;
            tr[x].tru=0;
            return;
        }
        if(l==r) tr[x].tru=1;
        tr[x].add+=v;
        tr[x].sum+=(tr[x].tru*v);
        return;
    }
    if(tr[x].add) down(x);
    change(x*2,l,r,v);
    change(x*2+1,l,r,v);
    update(x);
}
int find(int x,int l,int r)
{
    if(tr[x].l>r||tr[x].r<l) return -inf;
    if(tr[x].del) return -inf;
    if(l<=tr[x].l&&tr[x].r<=r) return tr[x].sum;
    if(tr[x].add) down(x);
    int a1=find(x*2,l,r);
    int a2=find(x*2+1,l,r);
    if(a1==-inf&&a2==-inf) return -inf;
    if(a1==-inf||a2==-inf) return max(a1,a2);
    return a1+a2;
}
signed main()
{
    scanf("%lld",&n);
    N=n;
    for(int i=1;i<=n;i++) scanf("%lld",&f[i]);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%lld%lld",&a,&b);
        build(a,b);
        build(b,a);
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld",&Ask[i].opt,&Ask[i].x);
        if(Ask[i].opt==1||Ask[i].opt==3) scanf("%lld",&Ask[i].y);
        if(Ask[i].opt==1) ++n,build(Ask[i].x,n),Ask[i].x=n;//Î´¼¤»î×´Ì¬ 
    }
    dfs1(1,0);
    dfs2(1,1);
    build_tr(1,1,n);//½¨Ê÷
    for(int i=1;i<=m;i++)
    {
        if(Ask[i].opt==1) change(1,pos[Ask[i].x],pos[Ask[i].x],Ask[i].y);
        else if(Ask[i].opt==2) change(1,pos[Ask[i].x],pos[Ask[i].x]+size[Ask[i].x]-1,-inf);
        else if(Ask[i].opt==3) change(1,pos[Ask[i].x],pos[Ask[i].x]+size[Ask[i].x]-1,Ask[i].y);
        else
        {
            int f1=find(1,pos[Ask[i].x],pos[Ask[i].x]+size[Ask[i].x]-1);
            if(f1==-inf) continue;
            printf("%lld\n",f1);
        }
    }
}
