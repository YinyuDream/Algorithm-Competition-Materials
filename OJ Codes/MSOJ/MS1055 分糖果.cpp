#include<cstdio>
using namespace std;
int a,b,c,d,m,w,x,y,z;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	w=a/3;b=b+w;d=d+w;a=a/3;
	x=b/3;c=c+x;a=a+x;b=b/3;
	y=c/3;b=b+y;d=d+y;c=c/3;
	z=d/3;c=c+z;a=a+z;d=d/3;
	printf("%d %d %d %d",a,b,c,d);
	return 0;
	
}