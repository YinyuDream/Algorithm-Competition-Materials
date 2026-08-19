#include<cstdio>
using namespace std;
int t;
int a[2];
int main()
{
	while(1)
	{
		int N;
		scanf("%d",&N);
		if(N==0)break;
		else
		{
			a[0]=0;
			for(int i=1;i<=N;i++)
			{
				scanf("%d",&a[1]); 
				if(a[1]>=a[0])t+=(a[1]-a[0])*6;
				else t+=(a[0]-a[1])*4;
				t+=5;
				a[0]=a[1];
			}
		}
		printf("%d\n",t);
		t=0;
	}
	return 0;
}
