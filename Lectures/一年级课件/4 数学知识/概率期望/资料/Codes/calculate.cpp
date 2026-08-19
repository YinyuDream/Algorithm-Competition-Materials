#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x[100001];
double p;
int main()
{
    freopen("calculate.in","r",stdin);
    freopen("calculate.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    for(i=1,j=n;i<j;i++)
      {
       while(j>0 && x[i]+x[j]>m)
         j--;
       p+=j-i;
      }
    p*=2;
    p/=n;
    p/=n-1;
    printf("%.2lf\n",p);
    return 0;
}
