#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,p;
int fa[maxn],d[maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	int f=find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=f;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1,l,r,w;i<=m;i++){
		scanf("%d%d%d",&l,&r,&w);
		int fx=find(l-1),fy=find(r);
		if(fx!=fy){
			fa[fx]=fy;
			d[fx]=w-d[l-1]+d[r];
		}else{
			if((d[l-1]-d[r]+p)%p!=w){
				printf("%d\n",i-1);
				return 0;
			}
		}
	}
	printf("%d\n",m);
	return 0;
}
