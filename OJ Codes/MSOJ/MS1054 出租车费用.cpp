#include<cstdio>
#include<cmath>
using namespace std;
double a,b;
int c;
int main(){
	scanf("%lf",&a);
	if(a<=2.5){
		b=8;
	}else{
		c=ceil(a-2.5);
		b=8+c*1.8; 
	}
	printf("%.1f",b);
	return 0;
}