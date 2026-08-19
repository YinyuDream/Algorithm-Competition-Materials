#include<bits/stdc++.h>
using namespace std;
int T;
long long n,k;
int main(){
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		if(n%2==1){
			if(k%2==1)
				puts("YES");
			else 
				puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}