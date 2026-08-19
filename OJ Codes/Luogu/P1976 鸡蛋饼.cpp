#include<cstdio>
using namespace std;
const int p=100000007;
long long n,a[3000];
int main(){
	scanf("%lld",&n);
	a[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			a[i]=(a[i]%p+(a[j]%p)*(a[i-j-1]%p))%p;
	printf("%lld",a[n]%p);
	return 0;
}
