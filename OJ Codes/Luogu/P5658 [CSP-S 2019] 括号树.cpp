#include<cstdio>
#include<stack>
using namespace std;
const int maxn=1e6+10;
int n,k,fa[maxn];
long long cnt[maxn],f[maxn],ans;
char a[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
stack<int>s;
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	int flag=0;
	if(a[u]=='(')s.push(u),flag=-1;
	else{
		if(s.size()){
			f[u]=f[fa[s.top()]]+1;
			flag=s.top();
			s.pop();
		}
	}
	cnt[u]=f[u]+cnt[fa[u]];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		dfs(v);
	}
	if(flag==-1)s.pop();
	else if(flag>0)s.push(flag);
}
int main(){
	//freoepn("brackets.in","r",stdin);
	//freopen("brackets.out","w",stdout);
	scanf("%d\n%s",&n,a+1);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&fa[i+1]);
		add(fa[i+1],i+1);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		ans^=(1ll*i*cnt[i]);
	printf("%lld",ans);
	return 0;
}