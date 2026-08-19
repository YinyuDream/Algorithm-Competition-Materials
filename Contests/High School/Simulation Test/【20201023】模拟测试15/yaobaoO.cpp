#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e3+10;
int n,m,k,cnt;
long long ans=0x7f7f7f7f7f7f7f7fll;
struct node{
	int to,next;
	long long wt;
}edge[2*maxn];
int head[maxn];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0,sign=1;
    while(!(ch>='0'&&ch<='9')){
    	if(ch=='-')sign=-sign;
    	ch=nc();
    }
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*sign;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void add(int u,int v,long long w)
{
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].wt=w;
	head[u]=cnt;
}
int book[maxn];
long long dis[maxn];
long long dij(long long val)
{
	if(val*k>=ans)return 0x7f7f7f7f7f7f7f7fll;
	priority_queue<pair<long long,int> > q;
	memset(book,0,sizeof book);
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v]==0&&dis[v]>dis[u]+max(0ll,edge[i].wt-val)){
				dis[v]=dis[u]+max(0ll,edge[i].wt-val);
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return val*k+dis[n];
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v;i<=m;i++){
		long long w;
		u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=0;i<=m;i++)
		ans=min(ans,dij(edge[i*2].wt));
	printf("%lld",ans);
	return 0;
}
