#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1e9+9;
int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res=1ll*res*a%p;
        }
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}
int main(){
    ll m,k;
    cin>>m>>k;
    ll val0=1,f0=1,g0=0,val1,f1,g1;
    for(int i=1;i<=k;i++){
        val1=val0+m-1;
        if(val1>=p){
            val1-=p;
        }
        f1=(f0*(val0-1)%p+m*(f0+1))%p;
        f1=f1*ksm(val1,p-2)%p;
        g1=(g0+m*f0)%p;
        f0=f1;
        g0=g1;
        val0=val1;
    }
    cout<<g0<<endl;
    return 0;
}