#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10,p=998244353;
int n,m,k;
long long len,sum;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],deg[maxn];
long long f[maxn],g[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
queue<int>q;
long long qpow(long long a,long long b)
{
	if(b==0)return 1;
	long long c=qpow(a,b/2);
	c=c*c%p;
	if(b&1)c=c*a%p;
	return c;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		deg[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	while(q.size()){
		int u=q.front();
		q.pop();
		f[u]++;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			f[v]=(f[u]+f[v])%p;
			g[v]=(g[v]+g[u]+f[u])%p;
			deg[v]--;
			if(!deg[v])
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		len=(len+g[i])%p,sum=(sum+f[i])%p;
	printf("%lld",len*qpow(sum,p-2)%p);
	return 0;
}
