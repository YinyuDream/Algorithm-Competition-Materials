#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m;
int fa[maxn];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		char opt;
		int u,v;
		scanf("\n%c%d%d",&opt,&u,&v);
		if(opt=='F'){
			int fx=find(u),fy=find(v);
			fa[fx]=fy;
		}
		else{
			int fx=find(x),fy=find(y);
			
		}
	}
	return 0;
}
