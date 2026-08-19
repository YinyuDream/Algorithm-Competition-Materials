#include<cstdio>
int a,b,n,ans;
int x,y,i; 
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	y=x=a/b;
	while(x>0)//求的y的总位数 
	{
		x=x/10;
		i++;
	}
	for(int j=1;j<=i-n+1;j++)
	{
		ans=y%10;
		y=y/10;
	}
	printf("%d",ans);
	return 0;
}
