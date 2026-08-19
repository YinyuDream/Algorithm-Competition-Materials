#include<cstdio>
using namespace std;
int a,b,c,D;
bool A,B,C;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	int x=10;
	for(;x<=100;x++){
	A=(x-a)%3;B=(x-b)%5;C=(x-c)%7;
	if(A==0&&B==0&&C==0)D+=1;break;
	}
	if(D==0||x==101)printf("No");
	if(D!=0&&x!=101)printf("%d",x);
	return 0;
}