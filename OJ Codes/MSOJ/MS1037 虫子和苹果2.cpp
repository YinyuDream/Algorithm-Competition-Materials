#include<cstdio>
using namespace std;
int n,x,y,a;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	if((n-(double)y/x)>=0){
		a=n-(double)y/x;
	printf("%d",a);
	}else{
		printf("0");
	}
	return 0;
}
