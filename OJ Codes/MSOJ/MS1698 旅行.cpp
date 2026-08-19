#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n,m,k;
vector<pair<int,int> >edge[maxn];
namespace subtask1
{
	void dfs(int u,int f)
	{
		printf("%d ",u);
		for(vector<pair<int,int> >::iterator it=edge[u].begin();it!=edge[u].end();it++)
			if(it->first!=f)
				dfs(it->first,u);
	}
	int work()
	{
		for(int i=1;i<=n;i++)
		sort(edge[i].begin(),edge[i].end());
		dfs(1,1);
	}
}
namespace subtask2
{
	int fa[maxn],line[maxn],circle[maxn],book[maxn],ans[maxn],dfn[maxn],cnt,top;
	bool is_small()
	{
		for(int i=1;i<=n;i++)
			if(dfn[i]>ans[i])return false;
			else if(dfn[i]<ans[i])return true;
			else continue;
		return false;
	}
	bool find_circle(int u,int f)
	{
		book[u]=1;
		for(vector<pair<int,int> >::iterator it=edge[u].begin();it!=edge[u].end();it++){
			int v=it->first;
			if(v!=f){
				if(book[v]){
					int now=u;
					circle[++cnt]=it->second;
					while(now!=v){
						circle[++cnt]=line[now];
						now=fa[now];
					}
					return true;
				}
				line[v]=it->second;
				fa[v]=u;
				if(find_circle(v,u))return true;
			}
		}	
	}
	void dfs(int u,int f,int cur)
	{
		dfn[++top]=u;
		for(vector<pair<int,int> >::iterator it=edge[u].begin();it!=edge[u].end();it++)
			if(it->first!=f&&it->second!=cur&&it->second!=(cur^1))
				dfs(it->first,u,cur);
	}
	void work()
	{
		memset(ans,0x3f,sizeof ans);
		for(int i=1;i<=n;i++)
		sort(edge[i].begin(),edge[i].end());
		find_circle(1,1);
		for(int i=1;i<=cnt;i++){
			top=0;
			dfs(1,1,circle[i]);
			if(is_small())
				for(int i=1;i<=n;i++)
					ans[i]=dfn[i];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(make_pair(v,k++));
		edge[v].push_back(make_pair(u,k++));
	}
	if(m==n-1)subtask1::work();
	else subtask2::work();
	return 0;
}