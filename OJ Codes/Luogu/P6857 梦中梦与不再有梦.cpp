#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n&1)printf("%lld\n",1ll*n*(n-1)/2);
		else printf("%lld\n",1ll*n*(n-1)/2-1ll*(n-2)/2);	
	}
	
	return 0;
}
