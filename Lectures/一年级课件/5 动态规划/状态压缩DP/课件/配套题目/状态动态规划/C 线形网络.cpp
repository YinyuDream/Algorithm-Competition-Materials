#include<fstream>
#include<cmath>
#include <iomanip>
using namespace std;
ifstream cin("c.in");
ofstream cout("c.out");

int n,m;
double a[22][5],len[22][22],cost[1048580][20];
int past[1048580];
double oo=1000000000;

void init()
{
    cin>>n;
    for (int c=0; c<n; c++) 
    {
        double i,j;
        cin>>a[c][1]>>a[c][2];
        for (int d=0; d<=c-1; d++) 
        {   i=a[d][1]-a[c][1];  j=a[d][2]-a[c][2];
            len[c][d]=len[d][c]=sqrt(i*i+j*j);
        }
    }
}

void work()
{
     int temp=1;  past[1]=1;
     for (int c=1; c<=n; c++) 
     {  temp*=2; past[temp]=1;   }
     
     
     for (int c=1; c<(1<<n); c++)
     {
         for (int d=0; d<n; d++) cost[c][d]=oo;
         if (past[c]==1) continue;
         for (int d=0; d<n; d++)
             if ((c & (1<<d))>0) 
             { 
                  for (int k=0; k<n; k++)
                      if ((c & (1<<k))>0 && d!=k)
                      {
                           double temp=cost[c-(1<<d)][k]+len[d][k];
                           if (past[c-(1<<k)]==1) temp=len[d][k];
                           cost[c][d]=min(cost[c][d],temp);
                      }
             }
     }
}

void print()
{
    int t;
    double ans;
    t=(1<<n)-1;  ans=cost[t][0];
    for (int c=1; c<n; c++) 
     ans=min(ans,cost[t][c]);
    cout<<fixed<<setprecision(2)<<ans<<' ';
}

int main()
{
    init();
    
    work();
    
    print();
    
    return 0;
}
