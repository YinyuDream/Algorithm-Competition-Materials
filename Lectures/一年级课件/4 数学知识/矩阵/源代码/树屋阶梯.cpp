#include<cstdio>
using namespace std;
long long n;
double a[3000];
int main(){
	scanf("%lld",&n);
	a[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			a[i]=(a[i]+a[j]*a[i-j-1]);
	double k=1;
	while(k<=1e70){
		printf("%.0f\n",k*=2);
	}
	printf("%.0f",a[n]);
	return 0;
}
