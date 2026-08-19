#include<cstdio>
using namespace std;
int n,temp;
int g,o,maxg,mino;
int N[110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&N[i]);
		if(N[i]%2==1)g++;
		else o++;
	}
	//printf("%d %d",g,o);
	for(int i=1;i<=n;i++)
	{
		maxg=i;
		for(int j=i;j<=n;j++)
		{
			if((N[j]%2==1&&N[j]>=N[maxg])||N[maxg]%2==0)
			{
				maxg=j;
			}
		}
		temp=N[maxg];
		N[maxg]=N[i];
		N[i]=temp;	
	}
	for(int i=g+1;i<=n;i++)
	{
		mino=i;
		for(int j=i;j<=n;j++)
		{
			if(N[j]%2==0&&N[j]<=N[mino])
			{
				mino=j;
			}
		}
		temp=N[mino];
		N[mino]=N[i];
		N[i]=temp;	
	}
	for(int i=1;i<=n;i++)printf("%d ",N[i]);
	return 0;
}
