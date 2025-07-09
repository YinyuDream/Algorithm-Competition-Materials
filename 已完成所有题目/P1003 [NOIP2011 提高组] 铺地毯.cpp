#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,x,y,ans=-1;
int a[maxn],b[maxn],g[maxn],k[maxn];
bool is_in(int x,int y,int index)
{
	if(x>=a[index]&&y>=b[index]&&x<=a[index]+g[index]-1&&y<=b[index]+k[index]-1)
		return true;
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w,l;i<=n;i++)
		scanf("%d%d%d%d",&u,&v,&w,&l),
		a[i]=u,b[i]=v,g[i]=w,k[i]=l;
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i++)
		if(is_in(x,y,i))
			ans=i;
	printf("%d",ans);
	return 0;
}