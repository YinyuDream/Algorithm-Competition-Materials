#include<cstdio>
using namespace std;
int a,b,c,x,y,z;
int main(){
	scanf("%d",&x);
	if(x<4||x==7){
		printf("0 0 0");
	}else{
	if(x%4==0){
		a=x/4;b=0;c=0;
	}else if(x%4==1){
		a=x/4-1;b=1;c=0;
	}else if(x%4==2){
		a=x/4-1;b=0;c=1;
	}else{
		a=x/4-2;b=1;c=1;
	}
	printf("%d %d %d",a,b,c);	
	}
	return 0;
}