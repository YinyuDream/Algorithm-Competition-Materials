#include<cstdio>
using namespace std;
int n,m;
int ai=1,bj=1;
int a[10010];
int b[5010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    
	for(int i=1;i<=m;i++)
	{
		for(int j=m-1;j>=i;j--)
		{
			int temp;
			if(b[j+1]<=b[j])
			{
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
			}
		}
	} 
	while(ai<=n && bj<=m)
	{
		while(a[ai]<=b[bj]&&ai<=n)
		{
			printf("%d ",a[ai]);
			ai++;
		}
		while(a[ai]>b[bj]&&bj<=m)
		{
			printf("%d ",b[bj]);
			bj++;
		}
	}
	if(ai<=n){for(int k=ai;k<=n;k++)printf("%d ",a[k]);}
	if(bj<=m){for(int k=bj;k<=m;k++)printf("%d ",b[k]);}
    return 0;
}
