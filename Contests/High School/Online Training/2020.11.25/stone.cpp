#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int maxn=3e5+10,maxk=1e6+10;
int n,q,k,new_k;
int fa[maxn][20],deep[maxn],c[maxk],tp,cnt;
struct node{
	int to,next,wt;
}edge[maxn],new_edge[maxk];
int head[maxn],new_head[maxk];
vector<pii>vec[maxn];
char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
void read(int &_num_){
	_num_=0;
    char ch=nc();
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')_num_=_num_*10+ch-48,ch=nc();
}
char to_write[5000005],help[15];
int pt,dfn[maxk],id[maxk],st_table[maxk][20],depth[maxk],tot;
void write(int x)
{
	if(!x)to_write[++pt]='0',to_write[++pt]='\n';
	else{
		int len=0;
		while(x)help[++len]=x%10+48,x/=10;
		for(;len;--len)to_write[++pt]=help[len];
		to_write[++pt]='\n';
	}
}
bool cmp(int a,int b)
{
	return dfn[a]<dfn[b];
}
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void new_add(int u,int v,int w)
{
	new_edge[++new_k].to=v;
	new_edge[new_k].next=new_head[u];
	new_edge[new_k].wt=w;
	new_head[u]=new_k;
}
void add_edge(int u,int v,int w)
{
	if(u==v||!u||!v)return ;
	vec[u].push_back(make_pair(v,w));
	vec[v].push_back(make_pair(u,w));
}
int sta[maxn],cur[maxn],_top;
void dfs()
{
	sta[++_top]=1;
	for(int i=1;i<=n;i++)
		cur[i]=head[i];
	loop:while(_top){
		int u=sta[_top];
		if(cur[u]==head[u])dfn[u]=++tot,id[tot]=u,depth[tot]=deep[u];
		for(int i=cur[u];cur[u]=edge[i].next,i;i=edge[i].next){
			int v=edge[i].to;
			if(v!=fa[u][0]){
				deep[v]=deep[u]+1;
				sta[++_top]=v;
				goto loop;
			}
		}
		id[++tot]=u;
		depth[tot]=deep[u];
		_top--;
	}
}
int _lg[maxk];
void get_st()
{
	_lg[0]=-1;
	for(int i=1;i<=tot;i++)
		_lg[i]=_lg[i>>1]+1;
	for(int i=1;i<=tot;i++)
		st_table[i][0]=i;
	for(int u=1;u<=n;u++)
		for(int i=1;(1<<i)<=deep[u];i++)
			fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int j=1;(1<<j)<=tot;j++)
	  for(int i=1;i+(1<<j)-1<=tot;i++){
	  	int u=st_table[i][j-1],v=st_table[i+(1<<(j-1))][j-1];
	  	if(depth[u]<=depth[v])st_table[i][j]=u;
	  	else st_table[i][j]=v;
	  }
}
int lca(int u,int v)
{
	int l=dfn[u],r=dfn[v];
	if(l>r)swap(l,r);
	int len=_lg[r-l+1],a=st_table[l][len],b=st_table[r-(1<<len)+1][len];
	return depth[a]<=depth[b]?id[a]:id[b];
}
int ance(int u,int delta)
{
	for(int i=delta;i;i-=i&(-i))
		u=fa[u][_lg[i&(-i)]];
	return u;
}
int st[maxk],top,orz;
int dis[maxk],book[maxk],que[maxk*4],front,back;
void bfs(int st,int &x,int &mx,int opt)
{
	front=1,back=0;
	que[++back]=st;
	dis[st]=0;
	book[st]=++orz;
	x=st;
	while(front<=back){
		int u=que[front++];
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].first,wt=vec[u][i].second;
			if(book[v]!=orz){
				dis[v]=dis[u]+wt;
				que[++back]=v;
				book[v]=orz;
				if(dis[v]>=mx)mx=dis[v],x=v;
			}
		}
		if(opt)vec[u].clear();
	}
}
void push(int x)
{
	if(!top){
		st[++top]=x;
		return ;
	}
	int z=lca(x,st[top]);
	while(top>1&&deep[z]<deep[st[top-1]]){
		add_edge(st[top-1],st[top],deep[st[top]]+deep[st[top-1]]-2*deep[lca(st[top],st[top-1])]);
		top--;
	}
	if(deep[z]<deep[st[top]]){
		add_edge(z,st[top],deep[st[top]]+deep[z]-2*deep[lca(z,st[top])]);
		top--;
	}
	if(!top||st[top]!=z)st[++top]=z;
	st[++top]=x;
}
int flag[maxn];
void calc(int u,int v,int len)
{
	if(deep[u]<deep[v])swap(u,v);
	u=ance(u,len/2);
	if(len%2==0)new_add(0,u,len);
	else{
		if(!flag[u])new_add(0,++tp,len),flag[u]=tp;
		else new_add(0,flag[u],len);
	}
}
void work()
{
	sort(c+1,c+cnt+1,cmp);
	int root=lca(c[1],c[n]);
	if(c[1]!=root)st[++top]=root;
	for(int i=1;i<=cnt;i++)
		push(c[i]);
	if(top)while(--top)add_edge(st[top],st[top+1],deep[st[top]]+deep[st[top+1]]-2*deep[lca(st[top],st[top+1])]);
	int l=0,r=0,mx=0;
	bfs(c[1],l,mx,0);
	bfs(l,r,mx,1);
	calc(l,r,mx);
}
bool in_stack[maxk];
void spfa()
{
	front=1,back=0;
	memset(dis,0x3f,sizeof dis);
	dis[0]=0;
	que[++back]=0;
	while(front<=back){
		int u=que[front++];
		in_stack[u]=0;
		for(int i=new_head[u];i;i=new_edge[i].next){
			int v=new_edge[i].to;
			if(dis[v]>dis[u]+new_edge[i].wt){
				dis[v]=dis[u]+new_edge[i].wt;
				if(!in_stack[v]){
					in_stack[v]=1;
					que[++back]=v;
				}
			}
		}
	}
}
void renew()
{
	for(int i=2;i<=n;i++){
		if(!flag[i]){
			new_add(i,fa[i][0],2);
			new_add(fa[i][0],i,2);
		}
		else{
			new_add(i,flag[i],1);
			new_add(flag[i],fa[i][0],1);
			new_add(flag[i],i,1);
			new_add(fa[i][0],flag[i],1);
		}
	}
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	read(n);
	for(int i=2;i<=n;i++){
		read(fa[i][0]);
		add(fa[i][0],i);
	}
	dfs(),get_st();
	read(q);
	for(int i=1;i<=q;i++){
		read(cnt);
		for(int j=1;j<=cnt;j++)
			read(c[j]);
		work();
	}
	renew();
	spfa();
	for(int i=1;i<=n;i++)
		write(dis[i]/2);
	fwrite(to_write+1,pt,1,stdout);
	return 0;
}
