#include<cstdio>
using namespace std;
int a,b;
int max(int x,int y)
{
	if(x>=y)return x;
	else return y;
}
int main()
{
	scanf("%d%d",&a,&b);
	printf("%d",max(a,b));
	return 0;
}
