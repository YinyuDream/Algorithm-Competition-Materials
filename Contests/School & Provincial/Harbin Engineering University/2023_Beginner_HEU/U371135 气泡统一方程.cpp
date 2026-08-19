#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,x;
ll R(ll x)
{
    return a*x*x+b*x+c;
}
ll R_1(ll x)
{
    return 2*a*x+b;
}
ll R_2(ll x)
{
    return 2*a;
}
int main(){
    cin>>a>>b>>c>>x;
    cout<<R(x)*R(x)*R_2(x)+2*R(x)*R_1(x)*R_1(x);
    return 0;
}