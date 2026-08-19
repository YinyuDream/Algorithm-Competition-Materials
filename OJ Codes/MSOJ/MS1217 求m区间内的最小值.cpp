#include<cstdio>
using namespace std;
const int maxn=2e6+10;
int m,n;
int a[maxn],ans[maxn];
int head,tail=0;
struct node{
	int id,num;
}queue[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		while(head<tail&&queue[tail-1].num>=a[i])tail--;
		queue[tail].num=a[i];
		queue[tail++].id=i;
		if(queue[tail-1].id-queue[head].id>=m)head++;
		ans[i]=queue[head].num;
	}
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}