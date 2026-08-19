#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
long long a[maxn],cf[maxn];
long long b[maxn],c[maxn];
inline int lowbit(int x)
{
	return x&(-x);
}
void build(int x,long long val)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		b[i]+=val;c[i]+=x*val;
	}
}
long long query(int x)
{
	long long ans=0;
	for(int i=x;i;i-=lowbit(i))
	{
		ans+=(x+1)*b[i]-c[i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
    cin>>m;
	for(int i=1;i<=n;i++)
		cf[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)
		build(i,cf[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
        string opt;
		long long k;
		cin>>opt;
		if(opt=="ADD"){
			scanf("%d%d%lld",&x,&y,&k);
			build(x,k);build(y+1,-k);
		}else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(x)-query(x-1));
		}
	}
	return 0;
}