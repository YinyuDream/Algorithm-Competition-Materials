#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n;
int a[maxn];
priority_queue<int>maxq;
priority_queue<int,vector<int>,greater<int> >minq;
int maxq_size,minq_size;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",a[1]);
	maxq.push(a[1]);
	for(int i=2;i<=n-2+n%2;i+=2)
	{
		/*if(a[i]<maxq.top())
		{
			minq.push(maxq.top());
			minq.pop();
			maxq.push(a[i]);
		}
		else minq.push(a[i]);
		i++;
		if(a[i]>minq.top())
		{
			maxq.push(minq.top());
			maiq.pop(); minq.push(a[i]);
		} 
		else maxq.push(a[i]);*/
		if(a[i]>a[i+1])swap(a[i],a[i+1]);
		if(a[i+1]<maxq.top())
		{
			maxq.push(a[i]);
			maxq.push(a[i+1]);
			minq.push(maxq.top());
			maxq.pop();
		}
		else if(a[i]<=maxq.top()&&a[i+1]>=maxq.top())
		{
			maxq.push(a[i]);
			minq.push(a[i+1]);
		}
		else
		{
			minq.push(a[i]);
			minq.push(a[i+1]);
			maxq.push(minq.top());
			minq.pop();
		}
		printf("%d\n",maxq.top());
	}
	return 0;
}
