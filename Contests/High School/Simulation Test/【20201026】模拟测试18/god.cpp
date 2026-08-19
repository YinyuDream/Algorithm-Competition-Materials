#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5e6+10;
int n,m,k,mx,top;
int w[maxn],step[maxn],book[maxn];
long long ans;
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void jsort()
{
	for(int i=mx;i;i--)
		for(int j=head[i];j;j=edge[j].next)
			step[++top]=edge[j].to;
}
int main()
{
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		add(w[i],i);
		mx=max(mx,w[i]);
	}
	jsort();
	memset(edge,0,sizeof edge);
	memset(head,0,sizeof head);
	k=0;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		book[step[i]]=1;
		for(int j=head[step[i]];j;j=edge[j].next){
			if(!book[edge[j].to]){
				ans+=w[edge[j].to];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
