#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e3+10;
int n,m,k,ans=0x7f7f7f7f;
int a[maxn][maxn],max_val[maxn][maxn],min_val[maxn][maxn];//max(min)_val[i][j]:第i列从j-k到j的最大(小)值
int maxx[maxn][maxn],minx[maxn][maxn];//第i行第j列-第i-k行第j-k列的最大/小值 
deque<int>q1,q2; 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			while(q1.size()&&a[q1.back()][i]>=a[j][i])q1.pop_back();
			if(q1.size()&&j-q1.front()+1>k)q1.pop_front();
			q1.push_back(j);
			min_val[i][j]=a[q1.front()][i];
			while(q2.size()&&a[q2.back()][i]<=a[j][i])q2.pop_back();
			if(q2.size()&&j-q2.front()+1>k)q2.pop_front();
			q2.push_back(j);
			max_val[i][j]=a[q2.front()][i];
		}
		while(q1.size())q1.pop_front();
		while(q2.size())q2.pop_front();
	}
	for(int i=k;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			while(q1.size()&&min_val[q1.back()][i]>=min_val[j][i])q1.pop_back();
			if(q1.size()&&j-q1.front()+1>k)q1.pop_front();
			q1.push_back(j);
			minx[i][j]=min_val[q1.front()][i];
			while(q2.size()&&max_val[q2.back()][i]<=max_val[j][i])q2.pop_back();
			if(q2.size()&&j-q2.front()+1>k)q2.pop_front();
			q2.push_back(j);
			maxx[i][j]=max_val[q2.front()][i];
		}
		while(q1.size())q1.pop_front();
		while(q2.size())q2.pop_front();
	}
	for(int i=k;i<=n;i++)
		for(int j=k;j<=m;j++)
			ans=min(ans,maxx[i][j]-minx[i][j]);
	printf("%d",ans);
	return 0;
}
