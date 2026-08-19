#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,wg,ws,ans=0x7f7f7f7f,tot,cnt;
struct node{
	int u,v,g,s;
}e[maxn];
int fa[maxn],s[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(node a,node b)
{
	if(a.g!=b.g)return a.g<b.g;
	return a.s<b.s;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&wg,&ws);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].g,&e[i].s);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			fa[j]=j;
		int p;
		for(p=tot;p;p--){
			if(e[s[p]].s>e[i].s)s[p+1]=s[p];
			else break;
		}
		tot++,s[p+1]=i;
		cnt=0;
		for(p=1;p<=tot;p++){
			int fx=find(e[s[p]].u),fy=find(e[s[p]].v);
			if(fx!=fy){
				fa[fx]=fy;
				s[++cnt]=s[p];
			}
		}
		if(cnt==n-1)
			ans=min(ans,e[i].g*wg+e[s[cnt]].s*ws);
		tot=cnt;
	}
	printf("%d",ans);
	return 0;
}
