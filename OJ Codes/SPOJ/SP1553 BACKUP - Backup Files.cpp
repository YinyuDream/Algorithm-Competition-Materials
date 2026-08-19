#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,k,T;
int num[maxn],net[maxn],pre[maxn],book[maxn];
long long a[maxn],ans;
struct node{
	int id;
	long long w;
	node(int _id,long long _w){
		id=_id,w=_w;
	}
	friend bool operator<(node a,node b){
		return a.w>b.w;
	}
};
priority_queue<node>q;
int main(){
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(book,0,sizeof book);
		while(q.size())q.pop();
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<n;i++)
			a[i]=num[i+1]-num[i];
		for(int i=1;i<=n-1;i++)
			net[i]=i+1;
		for(int i=1;i<=n-1;i++)
			pre[i]=i-1;
		a[0]=a[n]=0x7f7f7f7f7fll;
		for(int i=1;i<n;i++)
			q.push(node(i,a[i]));
		for(int i=1;i<=k;i++)
		{
			while(book[q.top().id])q.pop();
			node t=q.top();
			q.pop();
			ans+=t.w;
			book[pre[t.id]]=book[net[t.id]]=1;
			a[t.id]=a[pre[t.id]]+a[net[t.id]]-a[t.id];
			q.push(node(t.id,a[t.id]));
			net[t.id]=net[net[t.id]];
			pre[t.id]=pre[pre[t.id]];
			pre[net[t.id]]=t.id;
			net[pre[t.id]]=t.id;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
