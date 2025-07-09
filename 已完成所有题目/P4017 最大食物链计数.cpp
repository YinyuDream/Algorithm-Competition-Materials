#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,p=80112002;
int n,k,tot;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],in_deg[maxn],out_deg[maxn];
void add(int u,int v)
{
	edge[++tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
int ans,num[maxn],book[maxn];
queue<int>q;
void bfs()
{
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(!book[v]){
				num[v]+=num[u];
				num[v]%=p;
				in_deg[v]--;
				if(!in_deg[v]){
					book[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<=k;i++)
		scanf("%d%d",&u,&v),add(u,v),in_deg[v]++,out_deg[u]++;
	for(int i=1;i<=n;i++)
		if(!in_deg[i])
			q.push(i),num[i]=1,book[i]=1;
	bfs();
	for(int i=1;i<=n;i++)
		if(!out_deg[i])
			ans+=num[i],ans%=p;
	printf("%d\n",ans%p);
	return 0;
}