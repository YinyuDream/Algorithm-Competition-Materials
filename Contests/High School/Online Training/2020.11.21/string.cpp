#include<bits/stdc++.h>
const int maxn=1e6+10;
int T,n,m,ans;
int fa[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return 0;
	fa[fx]=fy;
	return 1;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		scanf("%d",&m);
		for(int i=1,s;i<=m;i++){
			scanf("%d",&s);
			for(int j=1;j+s<=n;j++){
				if(merge(j,j+s))ans--;
			}
		}
		printf("%d\n",ans);
	}
}
