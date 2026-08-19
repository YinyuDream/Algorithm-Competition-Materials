#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
ll k,a[maxn];
ll solve(int l,int r)
{
	if(l==r)return a[l]>=0;
	int mid=(l+r)/2;
	ll res=0;
	res+=solve(l,mid);
	res+=solve(mid+1,r);
	sort(a+l,a+mid+1);
	sort(a+mid+1,a+r+1);
	for(int i=mid+1,j=l;i<=r;i++){
		while(a[j]<=a[i]&&j<=mid)j++;
		res+=j-l;
	}
	return res;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]-=k;
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	printf("%lld",solve(1,n));
	return 0;
}