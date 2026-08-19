/*
4 3
5 6 2 4
1 2
0 1
2 3
3 4
------
13
*/ 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000+10;
int dp[maxn][maxn];//dp[i][j]表示以i这个点为根的子树分配j个人取得最优值
int n,m,a[maxn];
struct node{
	int left,right;
} tree[maxn];
int vis[maxn];//vis[u]表示u当前相连的孩子为那个
int dfs(int u,int x){//表示给u这个节点分配x个人取得的最优解 
	if(x==0 || u==0) return 0;
	if(dp[u][x]!=0) return dp[u][x];
	dp[u][x]=dfs(tree[u].right,x);//递归右孩子，且人数不减少,相当于先把x个人全部分配给右孩子。
	for(int i=1;i<=x;i++){//枚举人数分配 
		int t1=dfs(tree[u].left,i-1);
		int t2=dfs(tree[u].right,x-i);
		if(dp[u][x]<t1+t2+a[u]) dp[u][x]=t1+t2+a[u];
	}
	return dp[u][x];
}
int main()
{
	int u,v,root;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&u,&v);
		if(!vis[u]) tree[u].left=v;//没孩子 
		else tree[vis[u]].right=v;//已有孩子，则新的节点只能作为原孩子的右孩子 
		vis[u]=v;
		if(u==0) root=u; 
	}
	int ans=dfs(tree[root].left,m);
	printf("%d\n",ans);
	return 0;
} 
