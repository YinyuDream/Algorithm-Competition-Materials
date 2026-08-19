#include<cstdio>
using namespace std;
long long a,b,c,x,y,z;
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a<b){
		x=a;y=b;
	}else{
		x=b;y=a;
	}
	if(y<c){
		z=c;
	}else{
		if(c<x){
			z=y;y=x;x=c;
		}else{
			z=y;y=c;
		}
	}
	printf("%lld %lld %lld",x,y,z);
	return 0;
}