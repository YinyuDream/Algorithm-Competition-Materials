#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=30;
int n,m,k,maxt,mint=0x3f3f3f3f,ans,time,cnt=1;
bool book;
int mapp[maxn][maxn];
struct node{
	int x,y;
}p[maxn*maxn],s[maxn*maxn];
int main(){
	freopen("peanuts.in","r",stdin);
	freopen("peanuts.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mapp[i][j]);
			if(mapp[i][j]!=0)p[mapp[i][j]].x=i,p[mapp[i][j]].y=j,maxt=max(maxt,mapp[i][j]),mint=min(mint,mapp[i][j]);	
		}
	if(k<p[maxt].x)
	{
		printf("0");
		return 0;
	}
	time+=p[maxt].x;
	s[1].x=p[maxt].x,s[1].y=p[maxt].y;
	ans+=mapp[p[maxt].x][p[maxt].y];
	for(int i=maxt-1;i>=mint;i--)
	{
		if(p[i].x!=0&&p[i].y!=0)
		{
			if(time+abs(s[cnt].x-p[i].x)+abs(s[cnt].y-p[i].y)+1>k||time+s[cnt].x>k){
				cnt--;break;
			}
			time+=abs(s[cnt].x-p[i].x-1)+abs(s[cnt].y-p[i].y-1)+1;
			s[cnt].x=p[i].x,s[cnt].y=p[i].y;
			ans+=i,cnt++;
		}
	}
	printf("%d",ans);
	return 0;
}
