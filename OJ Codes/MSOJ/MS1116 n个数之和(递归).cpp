#include<cstdio>
using namespace std;
int n,temp;
int a[10010];
int f(int x)
{
		if(x==1)return a[1];
		return f(x-1)+a[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%d",f(n));
}
