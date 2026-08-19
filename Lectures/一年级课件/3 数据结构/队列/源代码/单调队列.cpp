#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n;
struct node
{
	int num;
	friend bool operator <(node x,node y)
	{
		return x.num>y.num;
	}
};
priority_queue<node> q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		node tmp;
		scanf("%d",&tmp.num);
		q.push(tmp);
	}
	while(q.size())
	{
		printf("%d ",q.top().num);
		q.pop();
	}
	return 0;
}
