#include<cstdio>
#include<deque>
using namespace std;
const int maxn=1e7+10;
int a[maxn];
int n,m; 
struct node{
	int ch,mx;
}ans[maxn];
deque<int> q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	q.push_back(n);
	for(int i=n;i>=1;i--)
	{
		if(q.empty())q.push_back(i);
		while(a[q.back()]<=a[i]&&q.back()!=i)q.pop_back();
		if(a[q.back()]>a[i]&&q.back()!=i)q.push_back(i);
		if(q.back()+m-1<=n)
		{
			ans[q.back()].ch=q.size();
			ans[q.back()].mx=a[q.front()];
			if(q.front()-q.back()+1>=m)q.pop_front();
		}
	}
	for(int i=1;i<=n-m+1;i++)
		printf("%d %d\n",ans[i].ch,ans[i].mx);
	return 0;
}
