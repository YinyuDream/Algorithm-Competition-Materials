#include<cstdio>
using namespace std;
typedef long long ll;
ll T,n,ansy,ansm;
ll a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is(ll year)
{
	if(year<0){
		if((year+1)%4==0)return true;
		return false;
	}
	if(year<1582&&year>0){
		if(year%4==0)return true;
		return false;
	}
	if(year>=1582){
		if(year%400==0)return true;
		if(year%4==0&&year%100!=0)return true;
		return false;
	}
}
ll day(ll year,ll month)
{
	if(year!=1582){
		if(month!=2)return a[month];
		return a[month]+is(year);
	}else{
		if(month!=10)return a[month];
		return 21;
	}
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ansy=-4713,ansm=1;
		scanf("%lld",&n);
		n++;
		if(n<=1721424){
			if(n%1461==0)ansy+=(n/1461)*4-4,n=n%1461+1461;	
			else ansy+=(n/1461)*4,n%=1461;
			while(n>day(ansy,ansm)){
				n-=day(ansy,ansm++);
				if(ansm==13)ansy++,ansm=1;
			}
			printf("%lld %lld %lld BC\n",n,ansm,-ansy);
			continue;
		}//<0
		n-=1721424;
		ansy=1;
		if(n<=577460){
			if(n%1461==0)ansy+=(n/1461)*4-4,n=n%1461+1461;	
			else ansy+=(n/1461)*4,n%=1461;
			while(n>day(ansy,ansm)){
				n-=day(ansy,ansm++);
				if(ansm==13)ansy++,ansm=1;
			}
			printf("%lld %lld %lld\n",n,ansm,ansy);
			continue;
		}//0-1582
		n-=577460;
		ansy=1582;
		if(n<=355){
			while(n>day(ansy,ansm))
				n-=day(ansy,ansm++);
			if(ansm==10&&n>4)n+=10;
			printf("%lld %lld %lld\n",n,ansm,ansy);
			continue;
		}//1582-1583
		n-=355;
		ansy=1583;
		if(n%146097==0)ansy+=(n/146097)*400-400,n=n%146097+146097;	
		else ansy+=(n/146097)*400,n%=146097;
		while(n>day(ansy,ansm)){
				n-=day(ansy,ansm++);
				if(ansm==13)ansy++,ansm=1;
		}
		printf("%lld %lld %lld\n",n,ansm,ansy);
	}
}