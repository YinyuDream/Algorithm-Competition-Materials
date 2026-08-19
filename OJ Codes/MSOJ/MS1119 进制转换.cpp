#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int a[64];
long long k,ans;
int f(long long x)//2-9----10
{
	int j=0,an=0,h;
	while(k>0)
	{
		h=k%10;
		k=k/10;
		an=an+h*pow(n,j);
		j++;	
	} 
	return an;
}
int g(long long x)//10----2-9
{
	int i=1,an=0;
	while(k>0)
	{
		a[i]=(int)k%m;
		k=k/m;
		i++;
			
	}
	for(int j=i-1;j>=1;j--)
	{
		an=an+a[j]*pow(10,j-1); 
	}
	 
	return an;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	if(n<m)
	{
		k=f(k);
		ans=g(k); 
	}
	if(n>m)
	{
		k=f(k);
		ans=g(k);
	}
	printf("%d",ans);
	return 0;
}