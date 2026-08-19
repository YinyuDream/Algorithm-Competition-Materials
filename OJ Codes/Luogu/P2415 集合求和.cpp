#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,t;
long long sum,a[maxn],pow_2[maxn];
int main(){
	pow_2[0]=1;
	for(int i=1;i<=30;i++)
		pow_2[i]=pow_2[i-1]*2;
	while(scanf("%d",&t)!=EOF)
		sum+=t,n++;
	sum*=pow_2[n-1];
	printf("%lld\n",sum);
	return 0;
}