#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k,cnt,cnt_edge;
int fa[maxn],ans[maxn],b[maxn],book[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void add(int u,int v)
{
	edge[++cnt_edge].to=v;
	edge[cnt_edge].next=head[u];
	head[u]=cnt_edge;
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy,cnt--;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	scanf("%d%d",&u,&v),u++,v++,add(u,v),add(v,u);
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=k;i++)
		scanf("%d",&b[i]),b[i]++,book[b[i]]=1;
	cnt=n-k;
	for(int i=1;i<=n;i++)
		if(!book[i])
			for(int j=head[i];j;j=edge[j].next)
				if(!book[edge[j].to])
					merge(i,edge[j].to);
	for(int i=k;i>=1;i--)
	{
		ans[i]=cnt;
		for(int j=head[b[i]];j;j=edge[j].next)
			if(!book[edge[j].to])
				merge(b[i],edge[j].to);
		book[b[i]]=0;
		cnt++;
	}
	ans[0]=cnt;
	for(int i=0;i<=k;i++)
		printf("%d\n",ans[i]);	
	return 0;
}
