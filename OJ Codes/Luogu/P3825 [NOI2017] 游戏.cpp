#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int n,m,d,k;
char mapp[maxn];
struct node{
	int to,next;
}edge[maxn*2];
int head[maxn];
struct cdt{
	int a,c;
	char x,y;
}ci[maxn];
char f[3][2]={{'B','C'},{'A','C'},{'A','B'}};
void add(int u,int v)
{
	edge[++k]={v,head[u]};
	head[u]=k;
}
int query(int a,char b)
{
	char t=mapp[a];
	if(t=='a'){
		if(b=='A')return -1;
		else if(b=='B')return 0;
		else return 1;
	}else if(t=='b'){
		if(b=='A')return 0;
		else if(b=='B')return -1;
		else return 1;
	}else{
		if(b=='A')return 0;
		else if(b=='B')return 1;
		else return -1;
	}
}
int pos_d[maxn];
void pre()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(mapp[i]=='x')
			pos_d[++cnt]=i;
}
int cnt,top,low[maxn],dfn[maxn],in[maxn],pos[maxn];
stack<int>st;
void tarjan(int u)
{
	dfn[u]=low[u]=++top;
	st.push(u);
	in[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(in[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		while(st.top()!=u){
			pos[st.top()]=cnt;
			in[st.top()]=0;
			st.pop();
		}
		pos[st.top()]=cnt;
		in[st.top()]=0;
		st.pop();
	}
}
void debug()
{
	for(int i=1;i<=n;i++)
		printf("%d ",mapp[i]);
	puts("");
}
bool work()
{
	k=cnt=top=0;
	memset(edge,0,sizeof edge);
	memset(head,0,sizeof head);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(pos,0,sizeof pos);
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;char x,y;
		a=ci[i].a,c=ci[i].c,x=ci[i].x,y=ci[i].y;
		b=query(a,x),d=query(c,y);
		if(b!=-1&&d!=-1){
			add(a+b*n,c+d*n);
			add(c+(d^1)*n,a+(b^1)*n);
		}else if(b!=-1&&d==-1){
			add(a+b*n,a+(b^1)*n);
		}
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(pos[i]==pos[i+n])
		return false;
	return true;
}
bool dfs(int x)
{
	if(x==d+1)return work();
	mapp[pos_d[x]]='a';
	if(dfs(x+1))return true;
	mapp[pos_d[x]]='b';
	if(dfs(x+1))return true;
	return false;
}
int main(){
	scanf("%d%d\n%s%d",&n,&d,mapp+1,&m);
	for(int i=1;i<=m;i++){
		int a,c;char x,y;
		scanf("%d %c%d %c",&ci[i].a,&ci[i].x,&ci[i].c,&ci[i].y);
	}
	pre();
	if(!dfs(1))return puts("-1"),0;
	for(int i=1;i<=n;i++)
		printf("%c",f[mapp[i]-'a'][pos[i]>pos[i+n]]);
	return 0;
}
