#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T,n,m,k,cnt,st,top;
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],deg[maxn],p[maxn],ans[maxn],book[maxn];
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs(int u)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!book[abs(edge[i].wt)]&&deg[v]%2==0){
			ans[++top]=edge[i].wt;
			book[abs(edge[i].wt)]=true;
			dfs(v);
		}
	}
}
int main(){
	freopen("travelling.in","r",stdin);
	freopen("travelling.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(head,0,sizeof head);
		memset(edge,0,sizeof edge);
		memset(deg,0,sizeof deg);
		memset(book,0,sizeof book);
		st=k=cnt=top=0;
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v,i);
			add(v,u,-i);
			deg[u]++;
			deg[v]++;
		}
		for(int i=1;i<=n;i++)
			if(deg[i]&1)
				p[++cnt]=i;
		for(int i=2;i<=cnt/2;i++){
			add(p[i*2-1],p[i*2],m+i);
			deg[p[i*2-1]]++;
			deg[p[i*2]]++;
		}
		st=cnt==0?1:p[1];
		dfs(st);
		printf("%d\n%d",max(0,(cnt-2)/2),top);
		for(int i=1;i<=top;i++)
			ans[i]>m?puts(""):printf(" %d",ans[i]);
	}
	return 0;
}
