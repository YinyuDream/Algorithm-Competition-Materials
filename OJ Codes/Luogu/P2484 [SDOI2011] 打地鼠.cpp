#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,r,c,ans=0x7f7f7f7f;
int mapp[maxn][maxn],a[maxn][maxn];
int sum;
bool check(int r,int c)
{
	if(sum%(r*c))return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=mapp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int t=a[i][j];
			for(int p=0;p<r;p++)
				for(int q=0;q<c;q++)
				{
					a[i+p][j+q]-=t;
					if(a[i+p][j+q]<0)return false;	
				}	
		}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&mapp[i][j]),
				sum+=mapp[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(check(i,j))
			ans=min(ans,sum/(i*j));
		}
	}
	printf("%d",ans);
	return 0;
}
