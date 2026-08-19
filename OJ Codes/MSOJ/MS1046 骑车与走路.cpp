#include<cstdio>
using namespace std;
int a;
double m,n;
int main(){
	scanf("%d",&a);
	m=a/1.2;
	n=a/3.0+50;
	if(m>n){
		printf("Bike");
	}else if(m==n){
		printf("All");
	}else{
		printf("Walk");
	}
	return 0;
}