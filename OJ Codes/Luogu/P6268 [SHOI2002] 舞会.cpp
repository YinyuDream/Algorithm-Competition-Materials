#include<cstdio>
using namespace std;
const int maxn=2e3+10;
int n,m,k,t,ans;
int book[maxn],head[maxn],mapp[maxn][maxn];
struct node{
	int to,next;
}edge[maxn*2];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int col[maxn],use[maxn],result[maxn];
void get_col(int u,int c)
{
	book[u]=1;
	col[u]=c;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(!book[v]){
			get_col(v,c^1);
		}
	}
}
bool dfs(int x)
{
	for(int i=1;i<=n;i++){
		if(mapp[x][i]&&use[i]!=t){
			use[i]=t;
			if(!result[i]||dfs(result[i])){
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		u++,v++;
		mapp[u][v]=mapp[v][u]=1;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!book[i])
			get_col(i,0);
	for(int i=1;i<=n;i++){
		if(col[i]){
			t++;
			if(dfs(i))ans++;
		}
	}
	printf("%d",n-ans);
	return 0;
}
