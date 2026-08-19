#include<cstdio>
int x,a,y,b;
double m;
int main(){
	scanf("%d%d%d%d",&x,&a,&y,&b);
	m=((double)a*x-b*y)/(a-b);
	printf("%.2f",m);
	return 0;
}
