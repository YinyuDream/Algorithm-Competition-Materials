#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n;
int fa[maxn],size[maxn],deep[maxn];
int find(int x)
{
	if(x==fa[x])return x;
	int f=find(fa[x]);
	deep[x]+=deep[fa[x]];
	fa[x]=f;
	return f;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<maxn;i++)
		fa[i]=i,size[i]=1;
	for(int i=1,x,y;i<=n;i++){
		char opt;
		scanf("\n%c",&opt);
		if(opt=='M'){
			scanf("%d%d",&x,&y);
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				fa[fx]=fy;
				deep[fx]=size[fy];
				size[fy]+=size[fx];
				size[fx]=0;
			}
		}else{
			scanf("%d",&x);
			find(x);
			printf("%d\n",deep[x]);
		}
	}
	return 0;
}
