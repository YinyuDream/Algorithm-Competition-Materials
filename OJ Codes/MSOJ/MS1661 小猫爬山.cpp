#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=20;
int n,m,ans=0x7f7f7f7f;
int a[maxn],w[maxn];
void dfs(int x,int cnt)
{
	if(cnt>=ans)return ;
	if(x==n+1){
		ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(w[i]+a[x]<=m)
		{
			w[i]+=a[x];
			dfs(x+1,cnt);
			w[i]-=a[x];
		}
	}
	w[cnt+1]+=a[x];
	dfs(x+1,cnt+1);
	w[cnt+1]-=a[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
