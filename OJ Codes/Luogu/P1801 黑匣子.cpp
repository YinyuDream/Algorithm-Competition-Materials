#include<cstdio>
#include<queue>
using namespace std;
const int maxn=200010;
int n,m,t=1;
int a[maxn],u[maxn];
priority_queue<int>maxq;//大根堆 
priority_queue<int,vector<int>,greater<int> >minq;//小根堆 
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&u[i]);

	maxq.push(a[1]);
	if(u[t]==1)printf("%d\n",maxq.top()),t++;
	for(int i=2;i<=m;i++)
	{
		if(a[i]>=maxq.top())minq.push(a[i]);
		else minq.push(maxq.top()),maxq.pop(),maxq.push(a[i]);
		while(u[t]==i)
		{
			while(maxq.size()!=t)
			{
				maxq.push(minq.top());
				minq.pop();
			}
			printf("%d\n",maxq.top());
			t++;
		}
	}
	return 0;
}
