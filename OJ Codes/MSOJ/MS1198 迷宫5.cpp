#include<cstdio>
using namespace std;
 
const int maxn=110;
int n,minx=1e8,s;
int a[maxn][maxn],b[maxn][maxn];
int x1,x2,y1,y2;
int dx[4]={0,1,0,-1};//hang
int dy[4]={1,0,-1,0};//lie
bool ca;
int lent[maxn][maxn];
int dj(int x1,int y1,int x2,int y2)
{
	if(b[x1][y1]!=b[x2][y2])return 2;
	else return 1;
}
void dfs(int x,int y)
{
    lent[x][y]=s;
    if(x==x2&&y==y2)
    {
        if(s<minx)minx=s; 
        return ;
    }
    int ddx=0,ddy=0;
    for(int i=0;i<=3;i++)
    {
        ddx=x+dx[i];ddy=y+dy[i];
        if(ddx>0 && ddy>0 && ddx<=n && ddy<=n && s+dj(x,y,ddx,ddy)<lent[ddx][ddy] && a[ddx][ddy]==0)
        {
            s+=dj(x,y,ddx,ddy);
            a[ddx][ddy]=1;
            dfs(ddx,ddy);
            a[ddx][ddy]=0;
            s-=dj(x,y,ddx,ddy);                    
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        scanf("%d",&b[i][j]);
        lent[i][j]=1e9;
        }
    }
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    a[x1][y1]=1;lent[x1][y1]=0;
    dfs(x1,y1);
    printf("%d",minx);    
    return 0;
}