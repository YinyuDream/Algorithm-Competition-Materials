#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n,k,ans,top2,top;
char ch[maxn],stack[maxn],s[maxn];
bool book[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
int sta[maxn];
void adde(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
bool cheak2(int len,int st)
{
	top2=0;
	for(int i=st;i<=st+len-1;i++)
	{
		if(stack[i]==')'&&top2==0)return false;
		if(stack[i]==')'&&top2!=0)top2--;
		if(stack[i]=='(')sta[++top2]=stack[i];
	}
	if(top2==0)return true;
	else return false;
}
void check1(int x)
{
	for(int i=2;i<=top;i++)
		for(int j=1;j+i-1<=top;j++)
			if(cheak2(i,j))s[x]++;		
}
void dfs(int x)
{
	book[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		{
			if(book[v]==0)
			{
				stack[++top]=ch[v];
				check1(v);
				dfs(v);
				top--;
			}
		}
	}
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf(" %c",&ch[i]);
	int u;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&u);
		adde(u,i+1),adde(i+1,u);
	}
	stack[++top]=ch[1],dfs(1),s[1]=0;
	for(int i=1;i<=n;i++)
		ans^=(i*s[i]);
	printf("%d",ans);
	return 0;
}
