#include<cstdio>
int n;
int cnt=0;
int book[10+10];//book[i]表示i这个数字是否已经被放，book[i]=0表示未放，book[i]=1表示已放 
void dfs(int x)//第x个盒子放数
{
	if(x==n+1)//来到了第n+1个盒子，则说明前n个盒子已经放好数，则表示形成了一个方案 
	{
		cnt++; return ;
	}
	//没有形成方案，则第x个盒子放数
	for(int i=1;i<=n;i++)//枚举第x个盒子能放数的范围，(1--n) 
	{
		if(book[i]==0)//说明i这个数没有被放 
		{
			book[i]=1;//表示i这个数被放
			dfs(x+1);//下一个盒子放数
			book[i]=0; //释放i这个数字
		}
	}
	
} 
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d\n",cnt);
	return 0;
}
