#include<cstdio>
using namespace std;
const int p=19;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	b=b+a*10;
	printf("%d",b/p);
	return 0;
 } 