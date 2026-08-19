#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,mx,l,r;
int a[maxn];
bool check(int val)
{
	long long sum=0;
	for(int i=1;i<=n;i++)
		if(mx-val<a[i])
			sum+=(long long)a[i]-mx+val;
	return sum>=m;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx=max(mx,a[i]);
	l=0,r=mx;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d",mx-l);
	return 0;
}