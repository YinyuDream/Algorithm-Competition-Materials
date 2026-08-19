#include<cstdio>
int a,g,s,b,A;
int main(){
	scanf("%d",&a);
	g=a%10;
	s=(a/10)%10;
	b=a/100;
	printf("%d%d%d",g,s,b);
    return 0;
}
