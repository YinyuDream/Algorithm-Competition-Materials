#include<cstdio>
using namespace std;
const int maxn=5e4+10;
int n,k,cnt;
int fa[maxn],re[maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	re[x]=(re[fa[x]]+re[x])%3;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		fa[i]=i,re[i]=0;
	for(int i=1;i<=k;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z>n||y>n||(x==2&&y==z)){
			cnt++;continue;
		}
		int fx=find(x),fy=find(y);
		if(x==1)
		{
			if(fx==fy)
			{
				if(re[y]!=re[z]){
					cnt++;continue;
				}
			}
			fa[fx]=fy;
			re[fx]=(3+re[fy]-re[fx])%3;
		}
		if(x==2)
		{
			if(fx==fy)
			{
				if(re[y]-re[z]!=1){
					cnt++;continue;
				}
			}
			fa[fx]=fy;
			re[fx]=(re[y]-re[z]+4)%3;
		}	
	}
	printf("%d",cnt);
	return 0;
}