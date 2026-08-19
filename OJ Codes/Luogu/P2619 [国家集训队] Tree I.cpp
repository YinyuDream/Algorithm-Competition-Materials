#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,l=-110,r=110,ans;
int fa[maxn];
struct node{
	int u,v,w,col;
}e[maxn];
bool cmp(node a,node b){
	if(a.w!=b.w)return a.w<b.w;
	else return a.col<b.col;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
pair<int,int> check()
{
	int cnt=0,sum=0;
	for(int i=0;i<n;i++)
		fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			sum+=e[i].w;
			cnt+=!e[i].col;
		}
	}
	return make_pair(sum,cnt);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].w,&e[i].col);
	while(l<=r){
		int mid=(l+r)/2;
		for(int i=1;i<=m;i++)
			if(!e[i].col)
				e[i].w+=mid;
		pair<int,int>tp=check();
		if(tp.second>=k)l=mid+1,ans=tp.first-k*mid;
		else r=mid-1;
		for(int i=1;i<=m;i++)
			if(!e[i].col)
				e[i].w-=mid;
	}
	printf("%d",ans);
	return 0;
}
