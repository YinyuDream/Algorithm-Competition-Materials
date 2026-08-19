#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
long long p,q=1,r;
inline long long gcd(long long a,long long b)
{
       if(b==0)
         return a;
       else
         return gcd(b,a%b);
}
inline int s(long long x)
{
       int p=0;
       while(x>0)
         {
          x/=10;
          p++;
         }
       return p;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      {
       p=p*i+q*n;
       q*=i;
       r=gcd(p,q);
       p/=r;
       q/=r;
      }
    r=p/q;
    p%=q;
    if(p==0)
      cout<<r<<"\n";
    else
      {
       for(i=s(r);i>0;i--)
         printf(" ");
       cout<<p<<"\n";
       if(r>0)
         cout<<r;
       for(i=s(q);i>0;i--)
         printf("-");
       printf("\n");
       for(i=s(r);i>0;i--)
         printf(" ");
       cout<<q<<"\n";
      }
    return 0;
}
