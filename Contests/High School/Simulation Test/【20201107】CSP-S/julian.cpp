#include<cstdio>
using namespace std;
typedef long long ll;
ll T,n,ansy=-4713,ansm=1;
ll a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll check(ll x)
{
	if(x%400==0)return 366;
	if(x%4==0&&x%100!=0)return 366;
	return 365;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ansy=-4713,ansm=1;
		scanf("%lld",&n);
		if(n<=1721422){
			ansy+=(n/1461)*4;
			n%=1461;
			if(n>366)n-=366,ansy++;
			while(n>365)n-=365,ansy++;
			while(n>(ansm==2?(((ansy+1)%4)==0?29:28):a[ansm])){
				n-=(ansm==2?(((ansy+1)%4)==0?29:28):a[ansm]);
				ansm++;
			}
			printf("%lld %lld %lld BC\n",n+1,ansm,-ansy);
			continue;
		}//<0
		n-=1721422;
		ansy=1;
		if(n<=577460){
			ansy+=(n/1461)*4;
			n%=1461;
			if(n>366)n-=366,ansy++;
			while(n>365)n-=365,ansy++;
			while(n>(ansm==2?((ansy%4)==0?29:28):a[ansm])){
				n-=(ansm==2?((ansy%4)==0?29:28):a[ansm]);
				ansm++;
			}
			printf("%lld %lld %lld\n",n,ansm,ansy);
			continue;
		}//0-1582
		n-=577460;
		ansy=1582;
		if(n<=355){
			if(n<=247){
				while(n>(ansm==2?((ansy%4)==0?29:28):a[ansm])){
					n-=(ansm==2?((ansy%4)==0?29:28):a[ansm]);
					ansm++;
				}
				printf("%lld %lld %lld\n",n,ansm,ansy);
			}else{
				ansm=10;
				n-=247;
				if(n<=16){
					printf("%lld\n",n+14);
					continue;
				}
				ansm=11,n-=16;
				while(n>(ansm==2?((ansy%4)==0?29:28):a[ansm])){
					n-=(ansm==2?((ansy%4)==0?29:28):a[ansm]);
					ansm++;
				}
				printf("%lld %lld %lld\n",n,ansm,ansy);
			}
			continue;
		}//1582-1583
		n-=355;
		ansy=1583;
		if(n<=6209){
			ansy+=(n/1461)*4;
			n%=1461;
			if(n>366)n-=366,ansy++;
			while(n>365)n-=365,ansy++;
			while(n>(ansm==2?((ansy%4)==0?29:28):a[ansm])){
				n-=(ansm==2?((ansy%4)==0?29:28):a[ansm]);
				ansm++;
			}
			printf("%lld %lld %lld\n",n,ansm,ansy);
			continue;
		}
		n-=6209;
		ansy=1600;
		ansy+=(n/146097)*400;
		n%=146097;
		while(n>check(ansy))n-=check(ansy),ansy++;
		while(n>(ansm==2?(check(ansy)==366?29:28):a[ansm])){
				n-=(ansm==2?(check(ansy)==366?29:28):a[ansm]);
				ansm++;
		}
		printf("%lld %lld %lld\n",n-1,ansm,ansy);
	}
}
