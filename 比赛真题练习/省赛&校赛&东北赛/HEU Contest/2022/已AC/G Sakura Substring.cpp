#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	ans=(long long)m*n*(n-1)/2;
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		if(i%2==0)printf("%d ",0);
		else printf("%d ",m);
	return 0;
}