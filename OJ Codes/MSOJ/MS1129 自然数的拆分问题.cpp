#include<cstdio>
using namespace std;
int n,k;
int a[100];
void print(int x)
{   a[k+1]=x;
	for(int m=1;m<k;m++)printf("%d+",a[m]);
	if(k>1)printf("%d",a[k]); 
	printf("\n");
}
void kfs(int x)
{
	
	if(x==0)print(x);
	else{
		for(int j=a[k];j<=x;j++)
	{
		k++;
		a[k]=j;
		kfs(x-j);
		k--;
	}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		k=1;
		a[1]=i;
		kfs(n-i);
	}
	return 0;
}
