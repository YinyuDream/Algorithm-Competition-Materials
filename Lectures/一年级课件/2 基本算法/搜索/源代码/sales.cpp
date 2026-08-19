#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=25;

int le[25];//le[i]表示i点回到第1个村子的路长度 
int book[maxn];//book[i]=0.第i点没有走过 
int n,ans=1e9;

struct edge//定义一个结构体，叫edge. 
{
	int w;//表示这条边的长度
	int to; //这条边的下个端点； 
};

edge len[25][25]; //在内存中声明了25*25个结构体类型的空间， 

//原来len[i][j]表示i点到j点的长度；
//现在len[i][j]表示i点周围第j条路。
 bool cmp(edge x,edge y)
 {
 	return x.w<y.w; 
 }

void dfs(int x,int y,int step)//走到第x个位置了，x是状态。当前状态走到y村子，距离为step 
{
	if(x==n)//一排n个盒子，每个盒子放一个村子，放到第n个盒子，就结束； 
	{
		if(step+le[y]<ans)ans=step+le[y];
		return;	
	} 
	
	 
	for(int i=2;i<=n;i++)//n种可能性。y周围的n条边，第一条边肯定是到自己的，不用尝试 
	{
		int next=len[y][i].to;//next是下个村子的编号。
		int nlen=len[y][i].w;//y村子到第一条边另外一头的村子距离。 
		if(step+nlen>=ans)return ;//因为是从小到大排序的，当前路径都不是最优，后面的路径肯定不是最优。 
		if(book[next]==0)
		{
			book[next]=1;
			dfs(x+1,next,step+nlen);
			book[next]=0;
		}
	}
}

int main()
{
	//freopen("sales.in","r",stdin);
	//freopen("sales.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//i是表示第i个村子。 
	{
		int temp; 
		for(int j=1;j<=n;j++)//n条边，刚开始，每一条边的另一个端点就是j; 
		{
			scanf("%d",&temp);
			len[i][j].to=j;	
			len[i][j].w=temp;
		}
		le[i]=len[i][1].w;
		sort(len[i]+1,len[i]+n+1,cmp);
		//按照cmp排序，排序以后，第一条边的端点肯定是自己，
		//第二条边的端点可能就不是2了 ,应该是w值最小的那个边的端点。 
	}		
	book[1]=1;
	dfs(1,1,0);//从第一个位置出发，放第一个村子， 
	printf("%d",ans);
	return 0;
}
