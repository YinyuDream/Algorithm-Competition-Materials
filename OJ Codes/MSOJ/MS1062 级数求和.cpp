#include<cstdio>
using namespace std;
int K,k;
double s=0;
int main()
{
	scanf("%d",&K);
	int n=1;
	for(int n=1;s<=K;n++)
	{
		s=s+1/(1.0*n);
		k=n;	
	}
	printf("%d\n",k);
	return 0;
}