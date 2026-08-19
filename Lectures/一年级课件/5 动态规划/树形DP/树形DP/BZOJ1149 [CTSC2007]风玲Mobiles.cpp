#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
int ch[maxn][2],n,minn=0x7f7f7f7f,ans=0,maxx=0;
void dfs(int x,int depth)
{
	if(x==-1) minn=min(minn,depth),maxx=max(maxx,depth);
	else
		dfs(ch[x][0],depth+1),
		dfs(ch[x][1],depth+1);
}
int solve(int x,int depth)
{
	if(x==-1)
	{
		if(depth==minn) return 1;
		else return 2;
	}
	int xx=solve(ch[x][0],depth+1);
	int yy=solve(ch[x][1],depth+1);
	if((xx==1&&yy==2)||(xx==1&&yy==3)||(xx==3&&yy==2)) ans++;
	if(xx==3&&yy==3) printf("-1"),exit(0);
	return xx|yy;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&ch[i][0],&ch[i][1]);
	dfs(1,1);
	if(maxx-minn>1) return printf("-1"),0;
	solve(1,1);
	printf("%d",ans);
	return 0;
}
