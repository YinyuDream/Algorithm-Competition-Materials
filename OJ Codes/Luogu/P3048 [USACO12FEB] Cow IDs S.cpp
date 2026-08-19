#include<cstdio>
using namespace std;
long long n,k,p,t,s;//p位数,t数量 
long long C(long long x,long long y)//c(x,y)
{
	if(y==0)return 1ll;
	long long tp=1;
	for(int i=1;i<=y;i++)
		tp*=(x-i+1);
	for(int i=1;i<=y;i++)
		tp/=i;
	return tp;
}
int main(){
	scanf("%lld%lld",&n,&k);
	while(t+C(p,k-1)<n)t+=C(p,k-1),p++;
	t=n-t,s=k-1;
	printf("1");
	for(int i=p;i>=1;i--){
		if(t<=C(i-1,s))printf("0");
		else printf("1"),t-=C(i-1,s),s--;
	}
	return 0;
}