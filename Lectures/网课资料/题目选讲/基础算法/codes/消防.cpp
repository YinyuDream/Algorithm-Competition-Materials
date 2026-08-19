#include<cstdio> 
#include<iostream> 
#include<algorithm> 
#include<cstring> 
#include<cstdlib> 
#include<cmath> 
#include<queue> 
#include<vector> 
#include<stack> 
using namespace std; 
const int inf=0x3f3f3f3f; 
const int maxn=300005;
inline void _read(int &x){ 
    char t=getchar();bool sign=true; 
    while(t<'0'||t>'9') 
    {if(t=='-')sign=false;t=getchar();} 
    for(x=0;t>='0'&&t<='9';t=getchar())x=x*10+t-'0'; 
    if(!sign)x=-x; 
} 
int tot_edge;
int dis[maxn],father[maxn],f[maxn*2];
bool vis[maxn];
int n,m,tot; 
struct line{ 
    int from,to,len; 
    line(){} 
    line(int a,int b,int c){from=a;to=b;len=c;} 
}; 
line edge[600005]; 
int last[300005],_next[600005]; 
void add_edge(int x,int y,int l){ 
    edge[++tot_edge]=line(x,y,l); 
    _next[tot_edge]=last[x]; 
    last[x]=tot_edge; 
} 
void bfs(int h){
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	int i,x,v;
	dis[h]=0;q.push(h);
	while(q.size()){
		x=q.front();q.pop();
		for(i=last[x];i;i=_next[i]){
			v=edge[i].to;
			if(dis[v]!=-1)continue;
			father[v]=x;
			if(vis[v])dis[v]=dis[x];
			else dis[v]=dis[x]+edge[i].len;
			q.push(v);
		}
	}
}
bool check(int k){
	int l=1,r=tot;
	while(f[1]-f[l+1]<=k&&l<=tot)l++;
	while(f[r-1]<=k&&r>=1)r--;
	return f[l]-f[r]<=m;
}
int main(){
	memset(last,-1,sizeof(last));
	_read(n);_read(m);
	int i,j,x,y,z;
	int from=0;
	int to=0;
	for(i=1;i<n;i++){
		_read(x);_read(y);_read(z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	bfs(1);
	for(i=1;i<=n;i++){
		if(dis[from]<dis[i])from=i;
	}
	bfs(from);
	for(i=1;i<=n;i++){
		if(dis[to]<dis[i])to=i;
	}
	int len=dis[to];
	f[++tot]=dis[to];vis[to]=1;
	while(to!=from){
		f[++tot]=dis[father[to]];
		to=father[to];
		vis[to]=1;
	}
	bfs(to);
	int l=0,r=len;
	for(i=1;i<=n;i++)l=max(l,dis[i]);
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l;
}
