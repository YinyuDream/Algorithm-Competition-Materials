#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e6+10,p=998244353;
int n,m,q,k;
int a[maxn];
struct node{
	int to,next;
}edge[maxn];
struct works{
	int opt,x,y;
}work[maxn];
int head[maxn];
vector<int>vec[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs(int u)
{
	if(work[u].opt==1){
		a[work[u].x]+=work[u].y;
		a[work[u].x]%=p;
		return ;
	}
	if(work[u].opt==2){
		for(int i=1;i<=n;i++)
			a[i]=(a[i]*work[u].x)%p;
		return ;
	}
	for(vector<int>::iterator it=vec[u].begin();it!=vec[u].end();it++)
		dfs(*it);
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d",&work[i].opt);
		if(work[i].opt==1){
			scanf("%d%d",&x,&y);
			work[i].x=x,work[i].y=y;
		}else if(work[i].opt==2){
			scanf("%d",&x);
			work[i].x=x;
		}else{
			scanf("%d",&x);
			for(int j=1;j<=x;j++){
				scanf("%d",&y);
				vec[i].push_back(y);
			}
		}
	}
	scanf("%d",&q);
	for(int i=1,v;i<=q;i++)
		scanf("%d",&v),dfs(v);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
