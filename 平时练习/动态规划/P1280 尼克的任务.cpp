#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
int ans[maxn];
struct node{
	int st,ed;
}a[maxn];
bool cmp(node p,node q)
{
	return p.ed<q.ed;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,p,q;i<=n;i++)
		scanf("%d%d",&p,&q),
		a[i].st=p,a[i].ed=p+q-1;
	sort(a+1,a+k+1,cmp);
	memset(ans,0x7f,sizeof ans);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			
	return 0;
}