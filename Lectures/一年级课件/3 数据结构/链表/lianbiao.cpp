#include<cstdio>
using namespace std;


int m,n;
int cnt;
int p[120],pre[120];
//p[i] 存储i这个人的后面的人的编号。 
//pre[i]i这个人前面的人的编号。 
int ans;//出队的人数 
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		p[i]=i+1;
		pre[i]=i-1;
	}
	pre[1]=m;
	p[m]=1;
	
	int k=1;
	while(ans<m)
	{
		cnt++;
		if(cnt==n)
		{
			p[pre[k]]=p[k];//k的前驱pre[k], 原来指向k,现在指向k的后面那个人p[k] 
			pre[p[k]]=pre[k];//k的后继p[k],原来前驱是k,现在指向k的前驱。 
			//比如三个人2,6,10；k=6，p[k]=10;pre[k]=2;
			//如果删除k这个人，只要将2指向10，p[2]=10;10指向2，pre[10]=2; 
			ans++;//出队一个，加1； 
			cnt=0;//口号清零并输出； 
			printf("%d ",k);
		}
		k=p[k]; //去下一个还在队列的人喊口号。 
	}
	return 0;
}
