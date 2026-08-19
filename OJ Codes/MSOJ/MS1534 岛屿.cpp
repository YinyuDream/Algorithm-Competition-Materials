#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=4e6+10;
int n,k=1;
struct node{
	int to,next;
	ll wt;
}edge[maxn*2];
int head[maxn];
void add(int u,int v,ll w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
int belong[maxn],book[maxn],flag[maxn],cnt;
ll ans;
void get_belong(int u,int bel)
{
	belong[u]=bel;
	for(int i=head[u];i;i=edge[i].next)
		if(!belong[edge[i].to])
			get_belong(edge[i].to,bel);
}
int fr_pt[maxn],cir[maxn],in_cir[maxn],tot;
ll fr_edge[maxn],wt_edge[maxn];
bool get_circle(int u,int fr)
{
	flag[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(i!=(fr^1)){
			if(flag[v]){
				int t=u;
				while(t!=v){
					cir[++tot]=t;
					wt_edge[tot]=fr_edge[t];
					in_cir[t]=1;
					t=fr_pt[t];
				}
				cir[++tot]=v;
				wt_edge[tot]=edge[i].wt;
				in_cir[v]=1;
				return true;
			}
			fr_pt[v]=u;
			fr_edge[v]=edge[i].wt;
			if(get_circle(v,i))return true;
		}
	}
	return false;
}
ll f[maxn],up[maxn];
void dfs(int u,int fr)
{
	ll mx=0,lmx=0;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(i!=(fr^1)&&!in_cir[v]){
			dfs(v,i);
			ll d=up[v]+edge[i].wt;
			if(d>=mx)lmx=mx,mx=d;
			else if(d>lmx)lmx=d;
			f[u]=max(f[u],f[v]);
		}
	}
	f[u]=max(f[u],mx+lmx);
	up[u]=mx;
	return ;
}
int q[maxn],front,back;
ll dp()
{
	ll num=0;
	front=1,back=0;
	for(int i=1;i<=tot;i++){
		cir[i+tot]=cir[i];
		wt_edge[i+tot]=wt_edge[i];
	}
	for(int i=1;i<=tot*2;i++)
		wt_edge[i]+=wt_edge[i-1];
	for(int i=1;i<=tot;i++){
		dfs(cir[i],-1);
		num=max(num,f[cir[i]]);
	}
	q[++back]=1;
	for(int i=2;i<=tot*2;i++){
		if(front<=back&&q[front]<i-tot+1)front++;
		num=max(num,up[cir[i]]+up[cir[q[front]]]+wt_edge[i-1]-wt_edge[q[front]-1]);
		while(front<=back&&up[cir[i]]-wt_edge[i-1]>=up[cir[q[back]]]-wt_edge[q[back]-1])back--;
		q[++back]=i;
	}
	return num;
}
ll work(int x)
{
	tot=0;
	book[belong[x]]=1;
	get_circle(x,-1);
	return dp();
}
int main(){
	scanf("%d",&n);
	for(int i=1,v;i<=n;i++){
		ll w;
		scanf("%d%lld",&v,&w);
		add(i,v,w);
		add(v,i,w);
	}
	for(int i=1;i<=n;i++)
		if(!belong[i])
			get_belong(i,++cnt);
	for(int i=1;i<=n;i++)
		if(!book[belong[i]])
			ans+=work(i);
	printf("%lld",ans);
	return 0;
}