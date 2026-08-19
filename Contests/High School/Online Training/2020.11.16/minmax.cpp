#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k,ans,delta,cnt,pt,cnt2,pt2,mxval;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn];
int in[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
namespace subtask1{
	int ans=0;
	void dfs(int u,int f,int mx,int mn)
	{
		if(mx-mn==delta)ans++;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				dfs(v,u,max(mx,edge[i].wt),min(mn,edge[i].wt));
			}
		}
	}
	void work()
	{
		for(int i=1;i<=n;i++){
			dfs(i,i,-1,0x7f7f7f7f);
		}
		printf("%d",ans/2);
	}
}
namespace subtask2{
	int wt[maxn],bk[maxn],top=0,ans=0;
	void work(int x)
	{
		for(int i=head[x];i;i=edge[i].next)
		wt[++top]=edge[i].wt;
		sort(wt+1,wt+top+1);
		for(int i=1;i<=top;i++)
			bk[wt[i]]++;
		for(int i=1;i<=top;i++)
			ans+=bk[wt[i]+delta];
		printf("%d",ans);
	}
}
namespace subtask3{
	int val[maxn],top;
	struct que{
		int qmax[maxn],qmin[maxn];
		int fr_mx,fr_mn,bk_mx,bk_mn;
		que(){
			memset(qmax,0,sizeof qmax);
			memset(qmin,0,sizeof qmin);
			fr_mx=fr_mn=1,bk_mx=bk_mn=0;
		}
		int query()
		{
			return val[qmax[fr_mx]]-val[qmin[fr_mn]];
		}
		void push(int x)
		{
			while(fr_mx<=bk_mx&&val[qmax[bk_mx]]<val[x])bk_mx--;
			qmax[++bk_mx]=x;
			while(fr_mn<=bk_mn&&val[qmin[bk_mn]]>val[x])bk_mn--;
			qmin[++bk_mn]=x;
		}
		void pop(int x)
		{
			if(fr_mn<=bk_mn&&qmin[fr_mn]<x)fr_mn++;
			if(fr_mx<=bk_mx&&qmax[fr_mx]<x)fr_mx++;
		}
	}q1,q2;
	void dfs(int x,int f)
	{
		for(int i=head[x];i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=f){
				val[++top]=edge[i].wt;
				dfs(v,x);
			}
		}
	}
	void work(int x)
	{
		int sum=0;
		dfs(x,x);
		for(int r=1,l1=0,l2=0;r<=n;r++){
			q1.push(r),q2.push(r);
			while(l1<=r&&q1.query()>delta)q1.pop(l1++);
			while(l2<=r&&q2.query()>=delta)q2.pop(l2++);
			sum+=l2-l1;
		}
		printf("%d",sum);
	}
}
namespace subtask4{
	int fa[maxn],size[maxn];
	struct _edge{
		int u,v,w;
	}e[maxn];
	void init(){
		for(int i=1;i<=n;i++)
			fa[i]=i,size[i]=1;
	}
	int find(int x)
	{
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	ll solve(int x,int y)
	{
		init();
		ll sum=0;
		for(int i=1;i<n;i++){
			if(e[i].w>y||e[i].w<x)continue;
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy){
				if(size[fx]>size[fy])swap(fx,fy);
				fa[fx]=fy;
				sum+=1ll*size[fx]*size[fy];
				size[fy]+=size[fx];
			}
		}
		return sum;
	}
	void work()
	{
		ll ans=0;
		for(int i=1;i+delta<=mxval;i++){
			ans+=solve(i,i+delta);
			ans-=solve(i+1,i+delta);
			ans-=solve(i,i+delta-1);
			ans+=solve(i+1,i+delta-1);
		}
		printf("%lld",ans);
	}
}
int main(){
	freopen("minmax.in","r",stdin);
	freopen("minmax.out","w",stdout);
	scanf("%d%d",&n,&delta);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		in[u]++,in[v]++;
		mxval=max(mxval,w);
		subtask4::e[i]=(subtask4::_edge){u,v,w};
	}
	for(int i=1;i<=n;i++){
		if(in[i]>1)
			cnt++,pt=i;
		if(in[i]==2)cnt2++;
		else pt2=i;
	}
	if(n<=5000)subtask1::work();
	else if(cnt==1)subtask2::work(pt);
	else if(cnt2==n-2)subtask3::work(pt2);
	else subtask4::work();
}
