#include<cstdio>
using namespace std;
int n,m,s;
int f(int x)
{
	int i=0; 
	for(;1;i++)
	{
		if(i*(i+1)/2>=n)break;
	}
	return i;
}
int main()
{	
	scanf("%d",&n);m=f(n)-1;
	m=n-(m*(m+1)/2);
	printf("%d %d",f(n),m);
	return 0;
}
