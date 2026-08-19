#include<cstdio>
using namespace std;
int a,b,x,y;
void ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0){
		x=1,y=0;return ;
	}
	ex_gcd(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-(a/b)*y;
}
int main(){
	scanf("%d%d",&a,&b);
	ex_gcd(a,b,x,y);
	printf("x=%d\ny=%d\n",x,y);
	return 0;
}
