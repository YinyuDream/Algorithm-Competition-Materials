#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans=0x7f7f7f7f;
int a[maxn];
char s[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int f[maxn],g[maxn],light[maxn],size[maxn];
void dfs(int u,int fr)
{
	int deg=0,delta=0x3f3f3f3f;
	light[u]=a[u],size[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fr){
			dfs(v,u);
			size[u]+=size[v];
			light[u]+=light[v];
			f[u]+=f[v];
			g[u]+=f[v];
			if(light[v]<size[v])
				delta=min(delta,g[v]-f[v]),deg++;
		}
	}
	if(light[u]<size[u]){
		f[u]+=deg+((deg&1)^a[u])+1;
		if(delta==0x3f3f3f3f)g[u]=!a[u];
		else g[u]+=delta+deg+(((deg&1)^a[u])^1);
	}else f[u]=g[u]=0;
}
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	scanf("%d\n%s",&n,s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		memset(light,0,sizeof light);
		memset(size,0,sizeof size);
		dfs(i,i);
		ans=min(ans,g[i]);
	}
	printf("%d\n",ans);
	return 0;
}
