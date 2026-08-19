#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i+=2){
	k=k+i;
	}
	printf("%d",k);
	return 0;
}
