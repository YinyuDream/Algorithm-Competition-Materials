#include<cstdio>
int a,b,n,d;
int main(){
	scanf("%d%d%d",&a,&b,&n);
	d=b-a;
	n=a+(n-1)*d;
	printf("%d",n);
	return 0;
}
