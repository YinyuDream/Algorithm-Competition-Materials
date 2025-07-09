#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	cnt=unique(a+1,a+n+1)-a-1;
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d ",a[i]);
	return 0;
}