#include<cstdio>
using namespace std;
int m,n,k=1,sum,a;
int p[5010],pre[5010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		p[i]=i+1;
		pre[i]=i-1;
	}
	p[n]=1;pre[1]=n;
	while(sum<n)
	{
		a++;
		if(a==m)
		{
			p[pre[k]]=p[k];
			pre[p[k]]=pre[k];
			sum++;
			a=0;
			printf("%d ",k);	
		}
		k=p[k];
	}
	return 0; 
}