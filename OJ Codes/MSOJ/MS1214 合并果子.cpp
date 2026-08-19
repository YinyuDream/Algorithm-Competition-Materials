#include<cstdio>
#include<queue>
using namespace std;
int n,ans;
struct node{
	int wt;
	friend bool operator <(node a,node b){
		return a.wt>b.wt;
	}
};
priority_queue<node> q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		node x;
		scanf("%d",&x.wt);
		q.push(x);
	}
	node tmp;
	while(q.size()>1)
	{
		tmp.wt=q.top().wt;
		q.pop();
		tmp.wt=(tmp.wt+q.top().wt);
		q.pop();
		q.push(tmp);
		ans+=tmp.wt;
	}
	printf("%d",ans);
	return 0;
}
