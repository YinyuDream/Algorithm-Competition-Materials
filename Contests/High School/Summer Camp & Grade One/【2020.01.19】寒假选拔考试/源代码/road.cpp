#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int min_ans=0x7f7f7f7f;
struct city{
	int e1,e2;
}p[10005];
struct node{
	int to,next,p;
}edge[10005];
int head[10005],book[10005];
struct country{
	int a,b,c;
}q[10005];
void add(int u,int v,int p)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].p=p;
	head[u]=k;
}
int dfs2(int x,int rode,int rail)
{
	int ans=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		if(ans>min_ans&&n>20)return 0x7f7f7f7f;
		if(edge[i].p==0&&book[i]==0){
			ans+=dfs2(edge[i].to,rode+1,rail);
		}
		else if(edge[i].p==0&&book[i]==1){
			ans+=dfs2(edge[i].to,rode,rail);
		}
		else if(edge[i].p==1&&book[i]==0){
			ans+=dfs2(edge[i].to,rode,rail+1);
		}
		else if(edge[i].p==1&&book[i]==1){
			ans+=dfs2(edge[i].to,rode,rail);
		}
	}
	if(x>n)ans=q[x].c*(q[x].a+rode)*(q[x].b+rail);
	return ans;
}
void dfs(int step)
{
	if(step==n){
		min_ans=min(min_ans,dfs2(1,0,0));
		return ;
	}
	book[p[step].e1]=1,dfs(step+1),book[p[step].e1]=0;
	book[p[step].e2]=1,dfs(step+1),book[p[step].e2]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		add(i,s>0?s:(-s+n),0);
		p[i].e1=k;
		add(i,t>0?t:(-t+n),1);
		p[i].e2=k;
	}
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		q[i+n].a=a,q[i+n].b=b,q[i+n].c=c;
	}
	dfs(1);
	printf("%d",min_ans);
	return 0;
}
