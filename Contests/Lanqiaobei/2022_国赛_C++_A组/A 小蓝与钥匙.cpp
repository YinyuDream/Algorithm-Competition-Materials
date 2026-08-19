#include <bits/stdc++.h>
using namespace std;
long long fac[15];
int main()
{
  fac[0]=1;
  for(int i=1;i<=14;i++)
    fac[i]=fac[i-1]*i;
  long long ans=0;
  for(int i=0;i<=14;i++)
    ans+=pow(-1,i)*fac[14]/fac[i];
  cout<<ans*40116600;
  return 0;
}