#include<cstdio>
using namespace std;
int a,b;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;return a;
	}
	int d=exgcd(b,a%b,x,y);
	int z=x;x=y,y=z-y*(a/b);
	return d;
}
int main(){
	scanf("%d%d",&a,&b);
	int x,y;
	exgcd(a,b,x,y);
	printf("%d",(x+b)%b);
	return 0;
}
