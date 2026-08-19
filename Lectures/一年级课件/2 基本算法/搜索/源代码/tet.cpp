#include<cstdio>
const int p=100000007;
int a,n;
int f(int x)//f(x)表示a的x次方幂，求a的x次方幂 
{
	if(x==1) return a;
	if(x==0) return 1;
	long long b=f(x/2);
	b=(b%p*b%p)%p;
	if(x%2==1) b=(b*a)%p;
	return b%p;
}
int main()
{
	scanf("%d%d",&a,&n);
	printf("%d\n",f(n)%p);
	return 0;
}
