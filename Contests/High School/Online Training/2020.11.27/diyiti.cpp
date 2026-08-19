#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int T,n,m,q,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],have[maxn],que[maxn],flag[maxn],deg[maxn],front,back;
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
	deg[v]++;
}
void work()
{
	int last=back;
	while(front<=last){
		int u=que[front++];
		if(flag[u]){
			que[++back]=u;
			continue;
		}
		for(int i=head[u],fr=head[u];i;fr=i,i=edge[i].next){
			int v=edge[i].to;
			if(!flag[v]){
				have[v]=1,deg[u]--,deg[v]--;
				if(!have[v])que[++back]=v;
				edge[fr].next=edge[i].next;
			}
			if(deg[u]>0)que[++back]=u;
		}
	}
}
int main(){
	freopen("diyiti.in","r",stdin);
	freopen("diyiti.out","w",stdout);
	back=0,front=1;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1,u;i<=m;i++){
		scanf("%d",&u);
		have[u]=1;
		que[++back]=u;
	}
	for(int i=1,opt,u;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&u);
			flag[u]^=1;
		}else if(opt==2){
			scanf("%d",&u);
			flag[u]^=1;
		}else if(opt==3){
			scanf("%d",&u);
			printf("%c\n",have[u]?'Y':'N');
		}else{
			work();
		}
	}
	return 0;
}
