#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
	{
		n++;
		if(n%3==0)n/=3;
		//printf("%lld\n",n);
		if(n==1){
			k-=i;
			n+=k%2;
			break;
		}
	}
	printf("%lld",n);
	return 0;
}