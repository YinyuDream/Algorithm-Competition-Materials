#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int n,r,q;
struct node{
	int s,w,id;
}a[maxn];
bool cmp(node a,node b)
{
	if(a.s!=b.s)return a.s>b.s;
	return a.id<b.id;
}
int main(){
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i].s),a[i].id=i;
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i].w);
	sort(a+1,a+n*2+1,cmp);
	while(r--)
	{
		for(int i=1;i<=n;i++)
			if(a[i*2-1].w>a[i*2].w)a[i*2-1].s++;
			else if(a[i*2-1].w<a[i*2].w)a[i*2].s++;
			else;
		sort(a+1,a+n*2+1,cmp);
	}
	printf("%d\n",a[q].id);
	return 0;
}
