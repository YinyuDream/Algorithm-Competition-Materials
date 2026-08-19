#include<cstdio>
using namespace std;
long long m,n;
long long temp;
int main(){
	scanf("%lld%lld",&m,&n);
	if(m<n){
	temp=m;
	m=n;
	n=temp;}
		while(m%n!=0)
	{
		temp=m%n;
		m=n;
		n=temp;}
	printf("%lld",n);
	return 0;
}