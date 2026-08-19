#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1e3+10;
int n,m,q,stx,sty,edx,edy,l=1,r=0x7f7f7f7f,ans,val;
int x[maxn*10],y[maxn*10],a[maxn][maxn],book[maxn][maxn];
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
struct node{
	int x,y,step;
	node(int _x,int _y,int _step){
		x=_x,y=_y,step=_step;
	}
};
int bfs()
{
	queue<node>q;
	q.push(node(stx,sty,0));
	book[stx][sty]=1;
	while(q.size())
	{
		node u=q.front();
		q.pop();
		if(u.x==edx&&u.y==edy)return u.step;
		for(int i=0;i<=3;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m||a[nx][ny]==1||book[nx][ny]==1)continue;
			book[nx][ny]=1;
			q.push(node(nx,ny,u.step+1));
		}
	}
	return -1;
}
int check(int t)
{
	t--;
	memset(book,0,sizeof book);
	memset(a,0,sizeof a);
	for(int i=1;i<=q;i++)
	{
		for(int j=y[i]-t;j<=y[i]+t;j++)
		{
			a[x[i]+t-abs(j-y[i])][j]=a[x[i]-t+abs(j-y[i])][j]=1;
		}
	}
	return bfs();
}
int main(){
	//freopen("escape.in","r",stdin);
	//freopen("escape.out","w",stdout);
	scanf("%d%d%d",&q,&n,&m);
	scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
	stx++,sty++,edx++,edy++;
	for(int i=1;i<=q;i++)
		scanf("%d%d",&x[i],&y[i]),x[i]++,y[i]++,
		r=min(r,min(abs(x[i]-stx)+abs(y[i]-sty),abs(x[i]-edx)+abs(y[i]-edy)));
	while(l<=r)
	{
		int mid=(l+r)/2,sum=check(mid);
		if(sum==-1)r=mid-1;
		else ans=sum,val=mid,l=mid+1;
	}
	printf("%d %d",val,ans);
	return 0;
}