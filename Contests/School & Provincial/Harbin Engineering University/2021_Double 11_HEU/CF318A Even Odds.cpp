#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	if(n%2==0){
		if(k<=n/2){
			printf("%lld",k*2-1);
		}else{
			printf("%lld",(k-n/2)*2);
		}
	}else{
		if(k<=n/2+1){
			printf("%lld",k*2-1);
		}else{
			printf("%lld",(k-n/2-1)*2);
		}
	}
	return 0;
}