#include<cstdio>
using namespace std;
int n,b1,b2;
int main(){
	scanf("%d",&n);
	b1=!(n&1),b2=(n>4&&n<=12);
	printf("%d %d %d %d",b1&&b2,b1||b2,(b1+b2)&1,(!b1)&&(!b2));
	return 0;
}
