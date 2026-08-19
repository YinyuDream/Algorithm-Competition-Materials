#include<cstdio>
using namespace std;
int n,m,sum;
int main(){
	scanf("%d%d",&n,&m);
	int i=n;
	if(n%2==0)i=n+1;
	for(;i<=m;i+=2)
	{	
		sum=sum+i;
	}
	printf("%d",sum);
	return 0;
}
