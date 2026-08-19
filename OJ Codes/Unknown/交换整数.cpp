#include<cstdio>
using namespace std;
int a,b;
void f(int &a,int &b)
{
	int temp;
	temp=b;
	b=a;
	a=temp; 
} 
int main()
{
	scanf("%d%d",&a,&b);
	f(a,b);
	printf("%d %d",a,b);
	return 0;
}
