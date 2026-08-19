#include<cstdio>
#include<cmath>
using namespace std;
int a,m,x;
char ch;
int main(){
	scanf("%d %c",&a,&ch);
	if(a<=1000){
		m=8;
	}else{
		x=(int)ceil((double)(a-1000)/500);
		m=4*x+8;
	}
	if(ch=='y'){
		m=m+5;
		printf("%d",m);
	}else{
		printf("%d",m);
	}
	return 0;
}
