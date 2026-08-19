#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,x,y,ans1,ans2;
int a[maxn],b[maxn];
int win[5][5]={
	{0,-1,1,1,-1},
	{1,0,-1,1,-1},
	{-1,1,0,-1,1},
	{-1,-1,1,0,1},
	{1,1,-1,-1,0}
};
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=x;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=y;i++)
		scanf("%d",&b[i]);
	for(int i=x+1;i<=n;i++)
		a[i]=a[i-x];
	for(int i=y+1;i<=n;i++)
		b[i]=b[i-y];
	for(int i=1;i<=n;i++)
	{
		if(win[a[i]][b[i]]==1)ans1++;
		else if(win[b[i]][a[i]]==1)ans2++;
		else ;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
