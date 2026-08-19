#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=200;
int len[maxn][maxn];
int book[maxn],dis[maxn];

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int t1,t2,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&w);
		len[t1][t2]=w;
		len[t2][t1]=w;//无向图需要反向建边 
	}
	int qd,zd;
	scanf("%d%d",&qd,&zd);
	memset(dis,0x3f,sizeof(dis));
	//函数需要导入cstring库。时间复杂度和for差不多。
	// 0，每一位是0;0x7f ,每一位21亿，有加减运算时候，不能用；0x3f,每一位10亿 ；
	//如果赋值其余数字慎重 ，可用for代替。 
	dis[qd]=0; 
	book[qd]=1;
	//算法主体 
	for(int i=1;i<=n-1;i++)//每次都有一个点能确定最短距离，n-1次能确定所有点的最短距离 
	{
		for(int j=1;j<=n;j++)//枚举每个点，尝试用最新的qd去稀释 周围的点的距离 
		{
			if(len[qd][j]>0 && dis[j]>dis[qd]+len[qd][j])
			{
				dis[j]=dis[qd]+len[qd][j];
			}
		}
		int minn=0;//初始值，dis[0]是无穷大;
		for(int j=1;j<=n;j++)//枚举所有点 
		{
			if(book[j]==0)//在没确定最小值的点中，找到最小值。表示这个值可以确定了。 
			{
				if(dis[j]<dis[minn])minn=j;
			}
		}
		book[minn]=1;//标记，minn这个点，已确定最短路。 
		qd=minn;//跟新qd，循环，用qd去稀释周围的点。 
		
	}
}
