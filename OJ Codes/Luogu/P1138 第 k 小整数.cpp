#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,cnt;
int a[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	cnt=unique(a+1,a+n+1)-a-1;
	if(k>cnt)puts("NO RESULT");
	else printf("%d\n",a[k]);
	return 0;
}