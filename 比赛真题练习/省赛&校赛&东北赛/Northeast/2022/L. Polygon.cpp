#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,sum;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		sum+=a[i];
	sum<=a[n]?puts("NO"):puts("YES");
	return 0;
}