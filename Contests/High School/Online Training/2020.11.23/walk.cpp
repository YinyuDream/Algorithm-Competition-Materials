#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int T,n,m,k,cnt,p;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],in[maxn],book[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int main(){
	scanf("%d",&T);
	while(T--){
		cnt=k=p=0;
		memset(head,0,sizeof head);
		memset(edge,0,sizeof edge);
		memset(in,0,sizeof in);
		memset(book,0,sizeof book);
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			in[u]++;
			in[v]++;
		}
		for(int i=1;i<=n;i++)
			if(in[i]&1)
				cnt++;
		if(cnt>2)continue;
		else if(cnt==2){
			for(int i=1;i<=n;i++){
				if(in[i]==1){
					p=i;
					break;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(in[i]>in[p]){
					p=i;
				}
			}
		}
		
	}
	return 0;
}
