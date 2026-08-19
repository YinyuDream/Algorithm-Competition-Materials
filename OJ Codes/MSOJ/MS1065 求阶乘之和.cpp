#include<cstdio>
using namespace std;
int a,j=1;
long long S=0,k=1;
int main(){
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		
		for(;j<=i;j++)
		{
			k=k*j;
		} 
	S=S+k;
	j=1;
	k=1;
	}
	printf("%lld",S);
	return 0;
}
