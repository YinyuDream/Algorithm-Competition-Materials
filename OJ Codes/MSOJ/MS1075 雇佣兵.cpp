#include<cstdio>
#include<cmath>
using namespace std;
int m,n,x;
int a,b,c;
int main()
{
    scanf("%d%d%d",&m,&n,&x);
    for(;x>=0;)
    {
    if((double)m/n>x)break;
    c=ceil((double)m/n);
    x=x-c;
    a=a+m;   
    b=m/n;
    n=n+b;
    a=a-m;
    }
printf("%d",n);
return 0;   
}
