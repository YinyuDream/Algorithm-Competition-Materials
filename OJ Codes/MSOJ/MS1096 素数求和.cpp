#include<cstdio>
#include<cmath>
using namespace std;
int N,sum,c;
int f(int x)
{
	 bool bo=0; 
	for(int j=2;j<=sqrt(x);j++)
	{
		if(x%j==0)
		{
			bo=1;
			break;
		}
	}
	if(bo==0)return 0;
	else return 1;
}
int main()
{
	scanf("%d",&N);
	for(int i=2;i<=N;i++)
	{
	if(f(i)==0)sum+=i;
	}
	printf("%d",sum);
	return 0;
}