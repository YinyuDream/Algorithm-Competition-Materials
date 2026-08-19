#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1e3+10;
int n,m,qx,qy,zx,zy,m1,m2;
int tail,head;
int mapp[maxn][maxn];
bool book[maxn][maxn];
int xy[4][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
struct node{
	int x,y,step;
}queue[maxn*maxn];
int main()
{
	cin>>n>>m>>m1>>m2;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
            scanf("%d",&mapp[i][j]);
            if(mapp[i][j]==3){
                qx=i;
                qy=j;
            }
            if(mapp[i][j]==4){
                zx=i;
                zy=j;
            }
        }
    }
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
			int nx=queue[head].x+m1*xy[i][0];
			int ny=queue[head].y+m2*xy[i][1];
			if(nx<1||ny<1||nx>n||ny>m)continue;
			if(mapp[nx][ny]!=0&&mapp[nx][ny]!=2&&book[nx][ny]==0)
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
        for(int i=0;i<=3;i++)
		{
			int nx=queue[head].x+m2*xy[i][0];
			int ny=queue[head].y+m1*xy[i][1];
			if(nx<1||ny<1||nx>n||ny>m)continue;
			if(mapp[nx][ny]!=0&&mapp[nx][ny]!=2&&book[nx][ny]==0)
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
	return 0;
}
