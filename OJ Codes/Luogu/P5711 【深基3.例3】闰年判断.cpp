#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n%100!=0)
		if(n%4==0)printf("1");
		else printf("0");
	else
		if(n%400==0)printf("1");
		else printf("0");
	return 0;
} 
