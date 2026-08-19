#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n,m;
     double ans=0;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
     double k=1.0/n;
    k*=2;
    ans=pow(k,m);
    printf("%0.15lf",ans);
    return 0;
}