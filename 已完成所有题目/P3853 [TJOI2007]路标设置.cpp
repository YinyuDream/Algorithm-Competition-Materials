#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int L,n,k,l=1,r;
int pos[maxn];
bool check(int val)
{
	int cnt=0;
	for(int i=1;i<n;i++){
		int delta=pos[i+1]-pos[i];
		cnt+=delta/val-(delta%val==0);
	}
	return cnt<=k;
}
int main(){
	scanf("%d%d%d",&L,&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&pos[i]);
	sort(pos+1,pos+n+1);
	for(int i=1;i<n;i++)
		r=max(r,pos[i+1]-pos[i]);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}