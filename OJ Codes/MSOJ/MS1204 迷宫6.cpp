#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,qx,qy,zx,zy;
int tail,head;
int mapp[maxn][maxn];
bool book[maxn][maxn];
int xy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
	int x,y,step;
}queue[maxn*maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&mapp[i][j]);
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	head=tail=1;
	queue[tail].x=qx;queue[tail].y=qy;queue[tail].step=0;
	tail++;
	if(qx==zx&&qy==zy){
		printf("0");return 0;
	}
	while(head<tail)
	{
		for(int i=0;i<=3;i++)
		{
			int nx=queue[head].x+xy[i][0];
			int ny=queue[head].y+xy[i][1];
			if(nx<1||ny<1||nx>n||ny>n)continue;
			if(mapp[nx][ny]==0&&book[nx][ny]==0)
			{
				if(nx==zx&&ny==zy)
				{
					printf("%d",queue[head].step+1);
					return 0;
				}
				book[nx][ny]=1;
				queue[tail].x=nx;queue[tail].y=ny;
				queue[tail].step=queue[head].step+1;
				tail++;
			}
		}
		head++;
	}
	printf("-1");
	return 0;
}
