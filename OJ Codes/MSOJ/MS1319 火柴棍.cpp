#include<cstdio>
using namespace std;

int n,maxn,minn,k,t;
bool bo;
int a[12]={6,2,5,5,4,5,6,3,7,6};
int ans[120];


void find(int x,int k,int r)
{
	if(r==0)
	{
		if(x<0)return ;
		else if(x==0)
		{	
			return ;
		}
		else
		{
			for(int i=0;i<=9;i++)
			{
				ans[k]=i;
				find(x-a[i],k+1);	
			}	
		}
	}
	else
	{
		
	}
}
int main(){
	scanf("%d",&n);
	k=1;
	for(int i=1;i<=n;i++)
	{
		ans[k]=i;
		find(n-a[i],k+1,0);
	}
	for(int i=n;i>=1;i--)
	{
		ans[k]=i;
		find(n-a[i],k+1,1);
	}
	return 0;
}
