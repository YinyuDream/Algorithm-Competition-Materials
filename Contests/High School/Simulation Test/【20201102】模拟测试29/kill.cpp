#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n;
double x,y,l,r=0x7f7f7f7f;
struct node{
	double x,y;
}p[maxn];
int fa[maxn];
double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
bool check(double x)
{
	for(int i=0;i<=n+1;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(dis(p[i],p[j])<x)
				merge(i,j);
	for(int i=1;i<=n;i++)
		if(y-p[i].y<x)
			merge(i,n+1);
	for(int i=1;i<=n;i++)
		if(p[i].y<x)
			merge(i,0);
	return find(0)!=find(n+1);
}
int main(){
	freopen("kill.in","r",stdin);
	freopen("kill.out","w",stdout);
	scanf("%d%d%d",&x,&y,&n);
	p[0].x=x,p[0].y=y;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		r=min(r,dis(p[0],p[i]));
	}
	while(r-l>1e-5){
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.2f",l);
	return 0;
}
