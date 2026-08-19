#include<cstdio>
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int n,a[maxn],s[maxn];
int get(int len)
{
	int ans=1;
	for(int i=1;i<=len;i++)
	ans+=s[i];
	
}
void dfs(int x,int top,int num)
{
	if(x==n+1){
		ans+=get();
		return ;
	}
	if(num and a[x]==0)
	{
		s[++top]=a[x];
		dfs(x+1,top);
		top--;
	}
	dfs(x+1,top);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	dfs(1,0);
	return 0;
}
