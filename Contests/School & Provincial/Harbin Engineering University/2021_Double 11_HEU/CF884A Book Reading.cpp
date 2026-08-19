#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,t,day;
int a[maxn];
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(t>0)
		t-=(86400-a[++day]);
	printf("%d",day);
	return 0;
}