#include<cstdio>
using namespace std;
const int maxn=4e6+10;
int n,k,ans;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],book[maxn],size[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
bool dfs(int u,int f)
{
	int sum=0;
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=f){
			dfs(v,u);
			size[u]+=size[v];
			if(!book[v])
			sum++;
		}
	}
	if(sum>=2){
		size[u]-=2;
		book[u]=1;
	}else if(sum==1)size[u]--;
}
int main(){
	//freopen("change.in","r",stdin);
	//freopen("change.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	printf("%d",size[1]*2-1);
	return 0;
}
