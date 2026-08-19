#include<cstdio>
using namespace std;
int N;
bool bo[5010];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		bo[i]=0;
	}
	for(int j=2;j<=N;j++)
	{
		for(int k=1;k<=N;k++)
		{
			if(k%j==0)
			{
				if(bo[k]==1)bo[k]=0;
				else bo[k]=1;
			}	
		}
	}
	for(int k=1;k<=N;k++)
	{
		if(bo[k]==0)printf("%d ",k);
	}
	return 0;
}