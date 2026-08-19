#include<cstdio>
using namespace std;
int n;
long long a[20];
int main(){
	scanf("%d",&n);
	a[0]=a[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			a[i]+=a[j-1]*a[i-j];
	printf("%lld",a[n]);
	return 0;
}
