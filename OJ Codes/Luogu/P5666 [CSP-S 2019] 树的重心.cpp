#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int minbalance;
struct node{
	int to,next,from;
}edge[maxn];
int head[maxn];
int k;
void add(int u,int v){edge[++k].to=v,edge[k].from=u,edge[k].next=head[u],head[u]=k;}
bool book_edge[maxn],book[maxn],visit[maxn];
int dfs(int x,int& ce,int treesize)
{
	book[x]=true;
	int sonsize=0,maxsonsize=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to,size;
		if(book[v]==0&&book_edge[i]==0)size=dfs(v,ce,treesize),sonsize+=size,maxsonsize=max(size,maxsonsize);
	}
	maxsonsize=max(maxsonsize,treesize-sonsize-1);
	if(maxsonsize<minbalance)minbalance=maxsonsize,ce=x;
	else if(maxsonsize==minbalance)ce+=x;
	return sonsize+1;
}
int getsize(int x){
	visit[x]=true;
	int t=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(visit[v]==0&&book_edge[i]==0)t+=getsize(v);
	}
	return t+1;
}
int main(){
	//freopen("centroid.in","r",stdin);
	//freopen("centroid.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1,ans,n,u,v,ce1=0,ce2=0;i<=t;i++)
	{
		k=ans=0;
		memset(edge,0,sizeof edge);
		memset(head,0,sizeof head);
		scanf("%d",&n);
		for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
		for(int i=1;i<n*2;i+=2)
		memset(book,0,sizeof book),
		memset(visit,0,sizeof visit),
		book_edge[i]=1,book_edge[i+1]=1,
		minbalance=0x7f7f7f7f,
		dfs(edge[i].from,ce1,getsize(edge[i].from)),
		minbalance=0x7f7f7f7f,
		dfs(edge[i].to,ce2,getsize(edge[i].to)),
		book_edge[i]=0,book_edge[i+1]=0, 
		ans+=(ce1+ce2);
		printf("%d\n",ans);	
	}
	return 0;
}