#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=3e6+10;
int n,m,cnt_edge,block,cnt_query,root=1,k,sum,l,r;
int a[maxn],size[maxn],fa[maxn][20],deep[maxn],pos[maxn],num[maxn],help[maxn],ans[maxn];
struct node{
	int to,next;
}edge[maxn];
struct query{
	int l,r,id,k;
}q[maxn];
int head[maxn];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void add_edge(int u,int v)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	head[u]=cnt_edge;
}
bool cmp(query a,query b)
{
	if(a.l/block==b.l/block)return a.r<b.r;
	else return a.l<b.l;
}
void lsh()
{
	for(int i=1;i<=n;i++)
		help[i]=a[i];
	sort(help+1,help+n+1);
	int cnt=unique(help+1,help+n+1)-help-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(help+1,help+cnt+1,a[i])-help;
}
void dfs(int u,int f)
{
	num[++k]=a[u];
	pos[u]=k;
	size[u]=1;
	for(int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			fa[v][0]=u;
			deep[v]=deep[u]+1;
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
int getson(int u,int v)
{
	int delta=deep[v]-deep[u]-1;
	for(int i=19;i>=0;i--)
		if(delta&(1<<i))
			v=fa[v][i];
	return v;
}
int bookl[maxn],bookr[maxn];
void add(int pos,int opt)
{
	if(opt==1){
		sum+=bookr[num[pos]];
		bookl[num[pos]]++;
	}else{
		sum+=bookl[num[pos]];
		bookr[num[pos]]++;
	}
}
void del(int pos,int opt)
{
	if(opt==1){
		sum-=bookr[num[pos]];
		bookl[num[pos]]--;
	}else{
		sum-=bookl[num[pos]];
		bookr[num[pos]]--;
	}
}
int main(){
	//srand((unsigned)time(0));
	n=read(),m=read();
	//root=rand()%n+1;
	for(int i=1;i<=n;i++)
		a[i]=read();
	lsh();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(root,root);
	for(int i=1;i<=n;i++)
		num[i+n]=num[i];
	root=1;
	for(int i=1,opt,x,y;i<=m;i++)
	{
		opt=read();
		if(opt==1){
			x=read();
			root=x;
		}else{
			x=read(),y=read();
			cnt_query++;
			int l1=pos[x],r1=pos[x]+size[x]-1,l2=pos[y],r2=pos[y]+size[y]-1;
			if(pos[root]>l1&&pos[root]<=r1){
				int tp=getson(x,root);
				l1=pos[tp]+size[tp];
				r1=pos[tp]+n-1;
			}else if(pos[root]==l1){
				l1=1;
				r1=n;
			}
			if(pos[root]>l2&&pos[root]<=r2){
				int tp=getson(y,root);
				l2=pos[tp]+size[tp];
				r2=pos[tp]+n-1;
			}else if(pos[root]==l2){
				l2=1;
				r2=n;
			}
			q[cnt_query*4-3]={l1-1,l2-1,cnt_query,1};
			if(q[cnt_query*4-3].l>q[cnt_query*4-3].r)
			swap(q[cnt_query*4-3].l,q[cnt_query*4-3].r);
			
			q[cnt_query*4-2]={l1-1,r2,cnt_query,-1};
			if(q[cnt_query*4-2].l>q[cnt_query*4-2].r)
			swap(q[cnt_query*4-2].l,q[cnt_query*4-2].r);
			
			q[cnt_query*4-1]={l2-1,r1,cnt_query,-1};
			if(q[cnt_query*4-1].l>q[cnt_query*4-1].r)
			swap(q[cnt_query*4-1].l,q[cnt_query*4-1].r);
			
			q[cnt_query*4]={r1,r2,cnt_query,1};
			if(q[cnt_query*4].l>q[cnt_query*4].r)
			swap(q[cnt_query*4].l,q[cnt_query*4].r);
		}
	}
	block=sqrt(n);
	sort(q+1,q+cnt_query*4+1,cmp);
	for(int i=1;i<=cnt_query*4;i++)
	{
		while(l<q[i].l)add(++l,1);
		while(l>q[i].l)del(l--,1);
		while(r>q[i].r)del(r--,2);
		while(r<q[i].r)add(++r,2);
		ans[q[i].id]+=q[i].k*sum;
	}
	for(int i=1;i<=cnt_query;i++)
		write(ans[i]),puts("");
	return 0;
}