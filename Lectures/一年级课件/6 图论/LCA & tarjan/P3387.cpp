#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int n,m,a[maxn],k;
struct node{
	int from,to,next;
} edge[maxn*10],ed[maxn*10];
int head[maxn];
int read(){
	int x=0,f=1; char ch; ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();} 
	return x*f;
}
void add(int u,int v){
	edge[++k].to=v; edge[k].from=u;
	edge[k].next=head[u]; head[u]=k;
}
int dfn[maxn],low[maxn],t=0;
int inStack[maxn];
int cnt=0;
stack<int> s;
int newNode[maxn],newA[maxn],head2[maxn],rd[maxn],dp[maxn];
void add2(int u,int v){
	ed[++k].to=v; ed[k].next=head2[u];head2[u]=k;
}
void tarjan(int u){
	dfn[u]=low[u]=++t;
	s.push(u);inStack[u]=true;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v); low[u]=min(low[u],low[v]);
		} else if(inStack[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cnt++;
		while(s.top()!=u){
			newNode[s.top()]=cnt; inStack[s.top()]=false;
			newA[cnt]+=a[s.top()]; s.pop();
		}
		newNode[s.top()]=cnt;inStack[s.top()]=false;
		newA[cnt]+=a[s.top()]; s.pop();
	}
}
void tp(){//Õÿ∆À≈≈–Ú«Ûdp[i] 
	queue <int> q;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(rd[i]==0){
			q.push(i);dp[i]=newA[i];
			ans=max(ans,dp[i]);	
		} 
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head2[u];i;i=ed[i].next){
			int v=ed[i].to;
			if(dp[v]<dp[u]+newA[v]){
				dp[v]=dp[u]+newA[v];
				ans=max(ans,dp[v]);
			}
			rd[v]--; if(rd[v]==0) q.push(v);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int u,v;
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++){
		u=read();v=read(); add(u,v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	k=0;
	for(int i=1;i<=m;i++){
		u=newNode[edge[i].from];v=newNode[edge[i].to];
		if(u!=v){add2(u,v); rd[v]++;}
	}
	tp();
	return 0;
} 
