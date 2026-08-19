#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn];
struct node
{
	int l,r,lazy,len,lmax,rmax,mmax; 
};
void build(int id,int x,int y)
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt<=1){
			update(1,x,y);
		}else{
			printf("%d\n",query(1,x,y));
		}
	}
	return 0;
}
