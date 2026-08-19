#include<cstdio>
using namespace std;
int n,x,y,a;
int maxx,maxn,maxm,minx=10000000;
bool bo=0;
int A[110][110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&A[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		bo=0;
		maxx=-1;
		for(int j=1;j<=n;j++)
		{
			if(maxx<A[i][j])
			{maxx=A[i][j];
			maxn=i;
			maxm=j;
			}
		}
		for(int k=1;k<=n;k++)
			{
				if(minx>A[k][maxm])minx=A[k][maxm];	
			}
		
		if(A[maxn][maxm]>minx)bo=1;
		if(bo==0)
		{
			printf("%d %d\n",maxn,maxm);
			a++;
		}
	}
	if(a==0)printf("not found");
	return 0;
}
