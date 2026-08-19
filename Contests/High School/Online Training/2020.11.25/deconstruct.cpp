#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10,p=1e9+7;
int n,k,ans,fa[maxn];
struct node{
	int to,next;
}edge[maxn];
int head[maxn];
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int sum[maxn],inv[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x;
}
int deep[maxn],q[maxn],_head=1,tail;
void bfs()
{
	q[++tail]=1;
	while(_head<=tail){
		int u=q[_head++];
		(ans+=sum[deep[u]])%=p;
		for(int i=head[u];i;i=edge[i].next){
			deep[edge[i].to]=deep[u]+1;
			q[++tail]=edge[i].to;
		}
	}
}
int main(){
	freopen("deconstruct.in","r",stdin);
	freopen("deconstruct.out","w",stdout);
	n=read();
	for(int i=2;i<=n;i++){
		fa[i]=read();
		add(fa[i],i);
	}
	inv[1]=sum[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=(1ll*(p-p/i)*inv[p%i])%p;
		sum[i]=(sum[i-1]+inv[i])%p;
	}
	bfs();
	printf("%d",ans);
	return 0;
}
