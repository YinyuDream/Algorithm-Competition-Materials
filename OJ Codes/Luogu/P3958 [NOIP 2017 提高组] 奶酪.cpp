#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int fa[maxn],T;
struct node{
	int x,y,z;
}a[maxn];
bool dis(long long x,long long y,long long z,long long _x,long long _y,long long _z,long long r)
{
	return (x-_x)*(x-_x)+(y-_y)*(y-_y)+(z-_z)*(z-_z)<=4*r*r;
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
int main(){
	scanf("%d",&T);
	while(T--)
	{
		int n,h,r;
		scanf("%d%d%d",&n,&h,&r);
		for(int i=0;i<=n+1;i++)
			fa[i]=i;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].z<=r)merge(i,0);
			if(h-a[i].z<=r)merge(i,n+1);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(dis(a[i].x,a[i].y,a[i].z,a[j].x,a[j].y,a[j].z,r))
					merge(j,i);
		if(find(0)==find(n+1))puts("Yes");
		else puts("No");
	}
	return 0;
}
