#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int t,n,m;
int a[maxn],b[maxn];
struct node{
	int l,r,opt;
}p[maxn];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
bool check()
{
	if(n==2)
	{
		if(m==1){
			if(t==1)return a[1]-b[1]==a[2]-b[2];
			else return b[1]-a[1]==a[2]-b[2];
		}
		else
		{
			return (a[1]+a[2]-b[1]-b[2])%2==0;
		}
	}
	sort(p+1,p+m+1,cmp);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
		for(int i=1;i<=m;i++)
		{
			int opt,u,v;
			scanf("%d%d%d",&opt,&u,&v);
			if(u>v)swap(u,v);
			if(t==1);
			p[i].l=u,p[i].r=v,p[i].opt=opt;
		}
		if(check())puts("YES");
		else puts("NO");
	}
	return 0;
}
