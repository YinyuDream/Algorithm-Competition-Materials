#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,x[200],y[200],a,b,f[3][100];
inline bool cmp(int a,int b)
{
       return a>b;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=3*n;i++)
      {
       scanf("%d",&x[i]);
       x[i]=x[i]*10000+i;
      }
    sort(x+1,x+3*n+1,cmp);
    for(i=1;i<=2*n;i++)
      if(i&1)
        {
         y[i]=1;
         a+=x[i];
        }
      else
        b+=x[i];
    for(;i<=3*n;i++)
      y[i]=2;
    while(a<5000000*n+10000 || b<5000000*n+10000)
      {
       do
         {
          i=(rand()*rand()+rand())%(2*n)+1;
          j=(rand()*rand()+rand())%(2*n)+1;
         }
       while(y[i]==0 || y[j]==1);
       swap(y[i],y[j]);
       a+=x[j]-x[i];
       b+=x[i]-x[j];
      }
    for(i=1;i<=3*n;i++)
      f[y[i]][++f[y[i]][0]]=x[i]%10000;
    for(i=0;i<3;i++)
      for(j=1;j<=f[i][0];j++)
        printf("%d\n",f[i][j]);
    return 0;
}
