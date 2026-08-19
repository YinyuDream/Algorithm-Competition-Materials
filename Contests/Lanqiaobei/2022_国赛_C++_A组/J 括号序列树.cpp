#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
int a[maxn],f[maxn],g[maxn];
struct node{
	int l,r;
}tree[maxn];
void update()
{
	int id=0;
	for(int i=1;i<=n*2;i++){
		if(a[i]==1){
			if(tree[id].l==0)
				tree[id].l=++cnt;
			id=tree[id].l;
		}else{
			if(tree[id].r==0)
				tree[id].r=++cnt;
			id=tree[id].r;
		}
	}
}
void dfs(int pos,int dep)
{
	if(pos==n*2+1){
		if(dep==0)
			update();
		return ;
	}
	a[pos]=1;
	dfs(pos+1,dep+1);
	if(dep){
		a[pos]=-1;
		dfs(pos+1,dep-1);
	}
}
void dp(int u)
{
	if(tree[u].l)
		dp(tree[u].l);
	if(tree[u].r)
		dp(tree[u].r);
	if(tree[u].l&&tree[u].r){
		f[u]=g[tree[u].l]+g[tree[u].r];
		g[u]=max(g[tree[u].l]+g[tree[u].r],max(f[tree[u].l]+g[tree[u].r],g[tree[u].l]+f[tree[u].r])+1);
	}else if(tree[u].l&&!tree[u].r){
		f[u]=g[tree[u].l];
		g[u]=max(f[tree[u].l]+1,g[tree[u].l]);
	}else if(!tree[u].l&&tree[u].r){
		f[u]=g[tree[u].r];
		g[u]=max(f[tree[u].r]+1,g[tree[u].r]);
	}
}
int main(){
	cin>>n;
	dfs(1,0);
	dp(0);
	cout<<g[0];
	return 0;
}