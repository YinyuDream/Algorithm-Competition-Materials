#include<cstdio>
using namespace std;
int n,m;
void f(int n,char a,char b ,char c )
{
    if(n==1)printf("%d %c->%c\n",n,a,c);
    else{f(n-1,a,c,b);
        printf("%d %c->%c\n",n,a,c);
        f(n-1,b,a,c);
    }
}
int main()
{
    scanf("%d",&n);
    m=n;
    f(n,'a','b','c');
    return 0;
}