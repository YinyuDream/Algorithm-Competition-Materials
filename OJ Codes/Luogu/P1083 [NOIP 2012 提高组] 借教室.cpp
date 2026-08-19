#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn],cf[maxn],l,r;
int s[maxn],e[maxn],w[maxn];
bool check(int pos)
{
	memset(cf,0,sizeof cf);
	for(int i=1;i<=pos;i++)
	cf[s[i]]+=w[i],cf[e[i]+1]-=w[i];
	for(int i=1;i<=n;i++)
	{
		cf[i]+=cf[i-1];
		if(cf[i]>a[i])return false;
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&w[i],&s[i],&e[i]);
	r=m;
	if(check(m))return puts("0"),0;
	puts("-1");
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
