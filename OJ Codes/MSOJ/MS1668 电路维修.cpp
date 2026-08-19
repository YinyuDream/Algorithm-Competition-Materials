#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=2e3+10;
int n,m,k;
char s[maxn];
struct graph{
	int to,next,wt;
}edge[2*maxn*maxn];
int head[maxn*maxn];
int book[maxn*maxn];
struct node{
	int id,d;
	node(int _id,int _d){
		id=_id,d=_d;
	}
};
deque<node>q;
void add(int u,int v,int w)
{
	edge[++k]={v,head[u],w};
	head[u]=k;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='\\'){
				add((i-1)*(m+1)+j,i*(m+1)+j+1,0);
				add(i*(m+1)+j+1,(i-1)*(m+1)+j,0);
				add(i*(m+1)+j,(i-1)*(m+1)+j+1,1);
				add((i-1)*(m+1)+j+1,i*(m+1)+j,1);
			}else{
				add((i-1)*(m+1)+j,i*(m+1)+j+1,1);
				add(i*(m+1)+j+1,(i-1)*(m+1)+j,1);
				add(i*(m+1)+j,(i-1)*(m+1)+j+1,0);
				add((i-1)*(m+1)+j+1,i*(m+1)+j,0);
			}
		}
	}
	if((n+m)%2)return puts("NO SOLUTION"),0;
	q.push_back(node(1,0));
	while(!q.empty())
	{
		while(q.size()&&book[q.front().id])q.pop_front();
		node u=q.front();
		book[u.id]=1;q.pop_front();
		if(u.id==(n+1)*(m+1))return printf("%d",u.d),0;
		for(int i=head[u.id];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(book[v]==1)continue;
			if(edge[i].wt==1)
			q.push_back(node(v,u.d+1));
			else
			q.push_front(node(v,u.d));
		}
	}
	puts("NO SOLUTION");
	return 0;
}