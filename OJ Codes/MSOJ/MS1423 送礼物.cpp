#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=50,maxn=(1<<23)+10;
int n,r,topb,topc;
long long w,ans,a[N],b[maxn],c[maxn];
void dfs1(int x,long long wt)
{
	if(x>=n/2){
		b[++topb]=wt;
		return ;
	}
	dfs1(x+1,wt);
	if(wt+a[x+1]<=w)dfs1(x+1,wt+a[x+1]);
}
void dfs2(int x,long long wt)
{
	if(x>=n){
		c[++topc]=wt;
		return ;
	}
	dfs2(x+1,wt);
	if(wt+a[x+1]<=w)dfs2(x+1,wt+a[x+1]);
}
int main(){
	scanf("%lld%d",&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<long long>());
	dfs1(0,0);
	dfs2(n/2,0);
	sort(b+1,b+topb+1);
	sort(c+1,c+topc+1);
	topc=unique(c+1,c+topc+1)-c-1;
	topb=unique(b+1,b+topb+1)-b-1;
	r=topc;
	for(int i=1;i<=topb;i++)
	{
		while(r>=1&&b[i]+c[r]>w)r--;
		ans=max(ans,b[i]+c[r]);
	}
	printf("%lld",ans);
	return 0;
}