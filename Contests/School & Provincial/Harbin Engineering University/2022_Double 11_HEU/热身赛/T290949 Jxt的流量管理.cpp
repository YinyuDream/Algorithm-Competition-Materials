#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int x,n;
int a[maxn],b[maxn];
int main(){
	scanf("%d%d",&x,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++)
		b[i]=b[i-1]+x-a[i];
	printf("%d",b[n+1]);
	return 0;
}