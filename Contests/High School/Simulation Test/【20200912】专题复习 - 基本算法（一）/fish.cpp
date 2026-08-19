#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=1e3+10;
int n,h,ans;
int d[maxn],t[maxn];
int dp[maxn][maxn];
struct node{
	int f,id;
	friend bool operator<(node a,node b)
	{
		return a.f<b.f;
	}
}a[maxn];
priority_queue<node>q;
int main(){
	//freopen("fish.in","r",stdin);
	//freopen("fish.out","w",stdout);
	scanf("%d%d",&n,&h);
	h=h*12;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].f),
		a[i].id=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for(int i=2;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=3;i<=n;i++)
		t[i]+=t[i-1];
	t[1]=0; 
	for(int i=1;i<=n;i++)
	{
		int tp=h-t[i],sum=0;
		while(q.size())q.pop();
		for(int j=1;j<=i;j++)
			q.push(a[j]);
		for(int j=1;j<=tp;j++)
		{
			node tmp=q.top();
			if(tmp.f>0)
				sum+=tmp.f;
			tmp.f-=d[tmp.id];
			q.pop();
			q.push(tmp);
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
