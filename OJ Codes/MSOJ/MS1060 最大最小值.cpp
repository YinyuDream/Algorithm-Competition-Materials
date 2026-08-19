#include<cstdio>
using namespace std;
int n;
long long MAX=-1,MIN=10000000001,a; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		if(a>MAX)MAX=a;
		if(a<MIN)MIN=a;
	}
	printf("%lld\n%lld\n",MAX,MIN);
	return 0;
}
