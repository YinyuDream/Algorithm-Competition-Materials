#include<cstdio>
using namespace std;
//fuck io
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
#define N 5000200
int n,a,head[N],cnt,st[N],rb,l1[N],r1[N],ct;
struct edge{int t,next;}ed[N];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;}
void dfs(int u,int fa){l1[u]=++ct;for(int i=head[u];i;i=ed[i].next)dfs(ed[i].t,u);r1[u]=ct;}
bool check(int x,int y){return l1[x]<=l1[y]&&r1[x]>=l1[y];}
int main()
{
	gi(n);
	for(int i=2;i<=n;i++)gi(a),adde(a,i);
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		while(rb&&!check(st[rb],i))rb--;
		st[++rb]=i;pi(rb,'\n');
	}
}