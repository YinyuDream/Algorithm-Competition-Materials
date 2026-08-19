#include<cstdio>
using namespace std;
const int maxn=1200;
int m,n,k,qx,qy,zx,zy;
bool mapp[maxn][maxn],book[maxn][maxn];
int fa[maxn][maxn],stp[maxn][maxn];
int xy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int head=1,tail=1;
struct node{
	int x,y,step;
};
node queue[maxn*maxn];
int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mapp[x][y]=1;
	}
	scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
	book[qx][qy]=1;fa[qx][qy]=1;stp[qx][qy]=0;
	queue[tail].x=qx;queue[tail].y=qy;queue[tail].step=0;
	tail++;
	if(qx==zx&&qy==zy){
		printf("0");return 0;
	}
	while(head!=tail)
	{
		for(int i=0;i<=3;i++)
		{
			int ddx=queue[head].x+xy[i][0];
			int ddy=queue[head].y+xy[i][1];
			if(ddx>m||ddx<1||ddy>n||ddy<1)continue;
			if(book[ddx][ddy]==1&&mapp[ddx][ddy]==0)
			{
				if(queue[head].step+1==stp[ddx][ddy])
				{
					fa[ddx][ddy]+=fa[queue[head].x][queue[head].y];continue;
				}
			}
			if(book[ddx][ddy]==0&&mapp[ddx][ddy]==0)
			{
				book[ddx][ddy]=1;
				queue[tail].x=ddx;
				queue[tail].y=ddy;
				queue[tail].step=queue[head].step+1;
				stp[ddx][ddy]=queue[head].step+1;
				fa[ddx][ddy]=fa[queue[head].x][queue[head].y];
				tail++;
			}	
		}
		head++;
	}
	if(fa[zx][zy]==0)printf("No Solution!");
	else printf("%d\n%d",stp[zx][zy],fa[zx][zy]);
	return 0;
}
