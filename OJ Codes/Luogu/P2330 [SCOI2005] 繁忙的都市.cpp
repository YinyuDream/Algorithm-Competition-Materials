#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
int n,m,u,v,w,ans,cnt;
int fa[maxn];
struct node{
	int x,y,val;
}edge[maxn];
bool cmp(node a,node b){
	return a.val<b.val;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),edge[i].x=u,edge[i].y=v,edge[i].val=w;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(edge[i].x),fy=find(edge[i].y);
		if(fx!=fy)fa[fx]=fy,cnt++,ans=max(ans,edge[i].val);
		if(cnt==n-1)break;
	}
	printf("%d %d\n",n-1,ans);
	return 0;
}
