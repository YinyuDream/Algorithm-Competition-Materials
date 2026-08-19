#include<cstdio>
#include<algorithm>
using namespace std;
const int N=21;
int n;
int dis[N][N];
int f[1<<N-1][N];
inline int min(int x,int y){
	return x>y?y:x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);
	int m=1;
	for(int i=0;i<=(1<<n)-1;i++)
	{
		if((1<<m)<=i)m++;
		for(int j=1;j<=m;j++)
		{
			if(i==(1<<j-1))f[i][j]=dis[1][j];
			else if(i&(1<<j-1))
			{
				f[i][j]=0x3f3f3f3f;
				for(int k=1;k<=m;k++)
				{
					if(((1<<k-1)&i)&&k!=j)
					{
						f[i][j]=min(f[i][j],f[i^(1<<j-1)][k]+dis[k][j]);
					}
				}
			}
			else ;	
		} 
	}
	int ans=0x3f3f3f3f;
	for(int i=2;i<=n;i++)
	{
		ans=min(ans,f[(1<<n)-1][i]+dis[i][1]);
	}
	printf("%d",ans);
	return 0;
}
