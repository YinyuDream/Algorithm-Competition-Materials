#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=2.2e6+10;

int n,k;
struct node{
	int to,next;
}edge[maxn];
int head[maxn],fa[maxn];
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& x){
		x=0; char c=gc();
		for(;c<'0'||c>'9';c=gc());
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
int dfn[maxn],size[maxn],top;
void dfs(int u)
{
	size[u]=1;
	dfn[u]=++top;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa[u]){
			dfs(v);
			size[u]+=size[v];
		}
	}
}
bool check(int x,int y)
{
	if(x>y)return false;
	for(int i=x;i<=y;i++)
		if(dfn[i]<dfn[x]||dfn[i]>=dfn[x]+size[x])
			return false;
	return true;
}
int solve(int x)
{
	int cnt=0,p=x;
	while(x){
		if(check(x,p))cnt++;
		x=fa[x];
	}
	return cnt;
}
int main(){
	freopen("ancestor.in","r",stdin);
	freopen("ancestor.out","w",stdout);
	gi(n);
	for(int i=2;i<=n;i++){
		gi(fa[i]);
		add(fa[i],i);
		add(i,fa[i]);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		pi(solve(i));
}
