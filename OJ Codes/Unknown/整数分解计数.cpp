#include<cstdio>
using namespace std;
int n,k,m,cnt;
int a[100];
void kfs(int x)
{
	
	if(x==0)cnt++;
	else{
		;
		for(int j=a[k];j<=x/2;j++)
	{
		k++;
		//if(k>m)break;
		a[k]=j;
		kfs(x-j);
		k--;
	}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n/2;i++)
	{
		k=1;
		a[1]=i;
		kfs(n-i);
	}
	printf("%d",cnt);
	return 0;
}
