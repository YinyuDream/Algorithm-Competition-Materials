#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m;
double ans;
int a[maxn];
struct node{
	int u,v,w;
}e[maxn];
int book[maxn];
void dfs(int pos,int sum)
{
	if(pos==n+1){
		if(!sum)return ;
		int t=0;
		for(int i=1;i<=m;i++)
			if(book[e[i].u]&&book[e[i].v])
				t+=e[i].w;
		if(t!=0)ans=max(ans,1.0*sum/t);
		return ;
	}
	dfs(pos+1,sum);
	book[pos]=1;
	dfs(pos+1,sum+a[pos]);
	book[pos]=0;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	dfs(1,0);
	printf("%.2f",ans);
	return 0;
}
