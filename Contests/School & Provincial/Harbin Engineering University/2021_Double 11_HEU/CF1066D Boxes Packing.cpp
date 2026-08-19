#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k,l,r;
int a[maxn],box[maxn];
bool check(int pos)
{
	memset(box,0,sizeof box);
	int t=1;
	for(int i=pos;i<=n;i++)
	{
		if(box[t]+a[i]>k)t++;
		if(t>m)return false;
		box[t]+=a[i];
	}
	return true;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",n-r);
	return 0;
}