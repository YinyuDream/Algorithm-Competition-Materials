#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100001;
int n,k;
int a[maxn];
int head[maxn];
int dp[maxn];
struct node{
	int to,next;
}tree[maxn];
void add(int x,int y)
{
	tree[++k].to=y;
	tree[k].next=head[x];
	head[x]=k;
}
void dfs(int x,int fa)
{
	if(dp[x]>-0x7f7f7f7f)return ;
	dp[x]=a[x];
	for(int i=head[x];i>0;i=tree[i].next)
	{
		if(tree[i].to==fa)continue;
		dfs(tree[i].to,x);
		if(dp[tree[i].to]>0)dp[x]+=dp[tree[i].to];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int p,q;
	for(int i=1;i<n;i++)
		cin>>p>>q,add(p,q),add(q,p);
	fill(dp+1,dp+n+1,-0x7f7f7f7f);
	int ans=-0x7f7f7f7f;
	dfs(1,1);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}