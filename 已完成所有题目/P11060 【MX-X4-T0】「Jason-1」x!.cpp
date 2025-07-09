#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
int main(){
    vector<ll> fac(21,1);
    for(int i=1;i<=20;i++) fac[i]=fac[i-1]*i;
    int n;
    cin>>n;
    cout<<(fac[n]%(n+1)?"NO":"YES")<<endl;
}