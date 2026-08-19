#include<cstdio>
using namespace std;
int n,cnt=1;
void f(int x)
{
	for(int i=1;i<=n;i++)cnt=cnt+i;
}
int main()
{
	scanf("%d",&n);
	f(n);
	printf("%d",cnt);
	return 0;
}
