#include<cstdio>
using namespace std;
double x,y;
int main(){
	scanf("%lf%lf",&x,&y);
	if(0<=x&&x<5){
		y=-x+2.5;
	}else if(5<=x&&x<10){
		y=2-1.5*(x-3)*(x-3);
	}else{
		y=x/2-1.5;
	}
	printf("%.3f",y);
	return 0;
}