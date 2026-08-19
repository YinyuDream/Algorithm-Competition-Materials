#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
int a[maxn],net[maxn],pre[maxn],book[maxn];
struct node{
	int id,w;
	node(int _id,int _w){
		id=_id,w=_w;
	}
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
priority_queue<node>q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k>n/2)return puts("Error!"),0;	
	for(int i=1;i<n;i++)
		net[i]=i+1;
	for(int i=2;i<=n;i++)
		pre[i]=i-1;
	net[n]=1;
	pre[1]=n;
	for(int i=1;i<=n;i++)
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
	printf("%d",ans);
	return 0;
}
