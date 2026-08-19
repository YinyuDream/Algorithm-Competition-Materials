#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,p,ans,cnt;
int s[maxn];
struct node{
	int t,w;
}a[maxn];
bool cmp(node a,node b)
{
	return a.t<b.t;
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	//freopen("move.in","r",stdin);
	//freopen("move.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].t,&a[i].w);
	sort(a+2,a+n+1,cmp);
	p=upper_bound(a+2,a+n+1,a[1],cmp)-a;
	if(p==n+1)return puts("1"),0;
	p--;
	ans=n-p+1;
	for(int i=p+1;i<=n;i++)
	q.push(a[i].w-a[i].t);
	for(int i=1;i;i++)
	{
		a[1].t-=q.top()+1;
		q.pop();
		while(p>1&&a[p].t>a[1].t)q.push(a[p].w-a[p].t),p--;
		if(a[1].t<0)break;
		ans=min(ans,n-p+1-i);
		if(q.empty())break;
	}
	printf("%d",ans);
	return 0;
}