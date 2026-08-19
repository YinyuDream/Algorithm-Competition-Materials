#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=40;
int n,m;
int c[maxn];
int ans1[1<<18],ans2[1<<18];
int a,b,pt,ans;
void dfs(int x,int mx,int num)
{
	if(x==mx+1){
		ans1[++a]=num%m;
		return ;
	}
	dfs(x+1,mx,(num+c[x])%m);
	dfs(x+1,mx,num);
}
void dfs2(int x,int mx,int num)
{
	if(x==mx+1){
		ans2[++b]=num%m;
		return ;
	}
	dfs2(x+1,mx,(num+c[x])%m);
	dfs2(x+1,mx,num);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]),c[i]%=m;
	if(n==1){
		printf("%d",c[1]);
		return 0;
	}
	dfs(1,n/2,0);dfs2(n/2+1,n,0);
	sort(ans1+1,ans1+a+1);
	sort(ans2+1,ans2+b+1);
	pt=b;
	for(int i=1;i<=a;i++)
	{
		while(ans1[i]+ans2[pt]>=m)pt--;
		if(ans<ans1[i]+ans2[pt])
		ans=ans1[i]+ans2[pt];
	}
	ans=max(ans,(ans1[a]+ans2[b])%m);
	printf("%d",ans);
	return 0;
}
