#include<cstdio>
using namespace std;
int a,b,c;
int k=0;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	for(int x=0;x<=(double)c/a;x++)
	{
		if((c-a*x)%b==0)k=k+1;
	}
	printf("%d",k);
	return 0;
}
