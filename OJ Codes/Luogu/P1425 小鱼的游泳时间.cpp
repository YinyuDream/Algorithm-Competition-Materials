#include<cstdio>
using namespace std;
int a,b,c,d;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
    int h=c-a,m=d-b;
    if(m<0)h--,m+=60;
	printf("%d %d\n",h,m);
    return 0;
}