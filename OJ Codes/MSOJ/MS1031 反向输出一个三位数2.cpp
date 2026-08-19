#include<cstdio>
int a,g,s,b,A;
int main(){
	scanf("%d",&a);
	g=a%10;
	s=(a/10)%10;
	b=a/100;
	A=g*100+s*10+b;
	printf("%d",A);
    return 0;
}
