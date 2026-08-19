#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,top;
double area,temp;
struct node{
	int x;int y;
}a[1000];
int ans[166167010];
double getlen(int x,int y)
{
	double len_2=(a[y].x-a[x].x)*(a[y].x-a[x].x)+(a[y].y-a[x].y)*(a[y].y-a[x].y);
	return sqrt(len_2);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				double a=getlen(i,j),b=getlen(i,k),c=getlen(j,k);
				double p=(a+b+c)/2;
				
				int f=2*sqrt(p*(p-a)*(p-b)*(p-c));
				ans[++top]=f;
			}
		}
	}
	sort(ans+1,ans+top+1);
	printf("%d",ans[k]);
	return 0;
}