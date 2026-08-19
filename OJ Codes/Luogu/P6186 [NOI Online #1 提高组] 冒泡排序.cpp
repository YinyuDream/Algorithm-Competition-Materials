#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],f[maxn],p[maxn];
void update(int p)
{
	for(int i=p;i<=n;i+=(i&(-i)))
	f[i]++; 
}
int ask(int p)
{
	int cnt=0;
	for(int i=p;i>=1;i-=(i&(-i)))
	cnt+=f[i];
	return cnt;
}
int query(int k)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	p[i]=a[i];
	for(int i=1;i<=min(k,n);i++)
	for(int j=1;j<n;j++)
	if(p[j]>p[j+1])
	swap(p[j],p[j+1]);
	memset(f,0,sizeof f);
	for(int i=n;i>=1;i--)
	{
		cnt+=ask(p[i]-1);
		update(p[i]); 
	}
	return cnt;
}
int main()
{
	//freopen("bubble.in","r",stdin);
	//freopen("bubble.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int opt,c;
		scanf("%d%d",&opt,&c);
		if(opt==1)swap(a[c],a[c+1]);
		else printf("%d\n",query(c));
	} 
	return 0;
}