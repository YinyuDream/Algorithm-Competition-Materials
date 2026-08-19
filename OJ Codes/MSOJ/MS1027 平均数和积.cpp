#include<cstdio>
int a,b,c;
double p;
long long sum;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	p=(double)(a+b+c)/3;
	sum=(long long)a*b*c;
	printf("%.2f\n",p);
	printf("%lld\n",sum);
	return 0;
}
