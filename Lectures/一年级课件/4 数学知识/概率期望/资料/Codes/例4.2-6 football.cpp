#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
double x[128][128],f[128][8];
int main()
{
    int i,j,k;
    while(1)
      {
       scanf("%d",&n);
       if(n==-1)
         break;
       for(i=0;i<(1<<n);i++)
         for(j=0;j<(1<<n);j++)
           scanf("%lf",&x[i][j]);
       for(i=0;i<(1<<n);i++)
         {
          f[i][0]=1;
          for(j=1;j<=n;j++)
            f[i][j]=0;
         }
       for(j=1;j<=n;j++)
         for(i=0;i<(1<<n);i++)
           for(k=((i^(1<<j-1))&(127-(1<<j-1)+1));k<=((i^(1<<j-1))|((1<<j-1)-1));k++)
             f[i][j]+=f[i][j-1]*f[k][j-1]*x[i][k];
       for(i=0,j=1;j<(1<<n);j++)
         if(f[j][n]>f[i][n])
           i=j;
       printf("%d\n",i+1);
      }
    return 0;
}
