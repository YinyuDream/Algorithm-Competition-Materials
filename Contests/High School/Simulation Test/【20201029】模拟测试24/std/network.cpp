#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int P=998244353;
void inc(int &x,int y){
	if ((x+=y)>=P) x-=P;
}
void inc(int &x, ll y){
	x=(x+y)%P;
}


const int N=2005;

int n;
int f[N][N*2][2];
int h[2][N*2];

struct edge{
	int adj,next;
	edge(){}
	edge(int _adj,int _next):adj(_adj),next(_next){}
} e[N*2];
int g[N],m;

inline void AddEdge(int u,int v){
	e[++m]=edge(v,g[u]);g[u]=m;
	e[++m]=edge(u,g[v]);g[v]=m;
}

int size[N];

int D;
int childList[N];

inline bool cmp_size(int x,int y){
	return size[x]<size[y];
}

void dfs(int u,int fa){
	size[u]=1;
	for (int i=g[u];i;i=e[i].next){
		int v=e[i].adj;
		if (v==fa) continue;
		dfs(v,u);
		size[u]+=size[v];
	}
	int childCount=0;
	for (int i=g[u];i;i=e[i].next){
		int v=e[i].adj;
		if (v==fa) continue;
		childList[++childCount]=v;
	}
	sort(childList+1,childList+childCount+1,cmp_size);
	for (int faChosen=0;faChosen<2;++faChosen){
		for (int a=0;a<2;++a){
			memset(h[0],0,sizeof(h[0]));
			int flag=0;
			if (a) h[0][D]=1;
			else h[0][D+(faChosen?1:-1)]=1;
			int sz=1;
			for (int i=1;i<=childCount;++i){
				int v=childList[i];
				memset(h[flag^1],0,sizeof(h[flag^1]));
				for (int i=D-size[v];i<=D+size[v];++i)if (f[v][i][a]){
					for (int j=D-sz;j<=D+sz;++j)if (h[flag][j])
						inc(h[flag^1][i+j-D],1LL*f[v][i][a]*h[flag][j]);		
				}
				sz+=size[v];
				flag^=1;
			}
			for (int i=0;i<=D+D;++i)
				inc(f[u][i][faChosen],h[flag][i]);
		}
	}
}

int solve(){
	memset(g,0,sizeof(g));m=1;

	scanf("%d",&n);
	D=n;
	for (int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		AddEdge(a,b);
	}
	
	memset(f,0,sizeof(f));
	dfs(1,0);
	
	int ans=0;
	for (int i=0;i<=D+D;++i)
		inc(ans,1LL*max(i-D-2,0)*f[1][i][1]);
	
	return 2LL*ans%P;
}

int main(){
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		printf("%d\n",solve());
	}
	return 0;
}
