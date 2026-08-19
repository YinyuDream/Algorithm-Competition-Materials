#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=(1e5)+10;

int n;
int sum;
int x[M];
int fa[M];
int size[M];

struct node{
	int u,v,w;
}edge[M];

inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp(node a,node b){
	return a.w<b.w;
}

int find(int a){
	while(a!=fa[a]) a=fa[a]=fa[fa[a]];
	return a;
}

int merge(int a,int b){
	fa[b]=a;
	size[a]+=size[b];
	x[a]+=x[b];
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	for(int i=1,u,v,w;i<n;i++){
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	}
	sort(edge+1,edge+n,cmp);
	for(int i=1;i<=n;i++) x[i]=read(),sum+=x[i];
	for(int i=1;i<n;i++){
		int dx=find(edge[i].u);
		int dy=find(edge[i].v);
		if(dx==dy) continue ;
		merge(dx,dy);
		if(size[dx]>sum-x[dx]) return printf("%d\n",edge[i].w),0;
	}
	puts("0");
	return 0;
}
