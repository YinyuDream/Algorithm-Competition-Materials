#include<cstdio>
using namespace std;
int n,x;
long long sum;
double p;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum=sum+x;
	}
	p=(double)sum/n;
	printf("%lld %.2f",sum,p);
	return 0;
}
