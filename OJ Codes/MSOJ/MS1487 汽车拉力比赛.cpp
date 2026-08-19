#pragma GCC optimize(2)
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=500+10;
int n,m,l,r,ans,qx,qy,cnt,t;
int mapp[maxn][maxn],flag[maxn][maxn],book[maxn][maxn];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
struct node{
	int x,y;
	node(int _x,int _y){
		x=_x,y=_y;
	}
};
bool check(int limit)
{
	t++;
	int now=1;
	queue<node>q;
	q.push(node(qx,qy));
	book[qx][qy]=t;
	while(q.size())
	{
		node u=q.front();q.pop();
		for(int i=0;i<=3;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m||abs(mapp[nx][ny]-mapp[u.x][u.y])>limit||book[nx][ny]==t)continue;
			q.push(node(nx,ny));
			now+=flag[nx][ny];
			if(now==cnt)return true;
			book[nx][ny]=t;
		}
	}
	return false;
}
int main(){
	//freopen("car.in","r",stdin);
	//freopen("car.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mapp[i][j]=read(),
			r=max(r,mapp[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			flag[i][j]=read();
			cnt+=flag[i][j];
			if(flag[i][j]==1)
			qx=i,qy=j;
		}
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}