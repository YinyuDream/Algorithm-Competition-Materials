#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k;
int ans[maxn],p[maxn];
void to_min()
{
	bool flag=0;
	for(int i=1;i<=n;i++)
		if(ans[i]==p[i])continue;
		else if(ans[i]<p[i])break;
		else flag=1;
	if(flag)
		for(int i=1;i<=n;i++)
			ans[i]=p[i];
}
void dfs(int step)
{
	to_min();
	if(step>=10)return ;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(abs(i-j)>=k&&abs(p[i]-p[j])==1)
				swap(p[i],p[j]),dfs(step+1),swap(p[i],p[j]);
}
int main(){
	freopen("perfect.in","r",stdin);
	freopen("perfect.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),ans[i]=p[i];
	dfs(0);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}
