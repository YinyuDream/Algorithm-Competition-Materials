#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace GenHelper{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get(){
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<< 3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read(){
        while(!u)
            u=get();
        bool res=u&1;
        u>>=1;
        return res;
    }
    void srand(int x){
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
        u=0;
    }
}
using namespace GenHelper;
bool edge[8005][8005];
int main(){
    int n,seed;
    cin>>n>>seed;
    srand(seed);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            edge[j][i]=edge[i][j]=read();
    ll ans=1ll*n*(n-1)*(n-2)/6;
    ll tot=0;
    for(int i=1;i<=n;i++){
        int cnt_0=0,cnt_1=0;
        for(int j=1;j<=n;j++){
            if(j!=i){
                if(edge[i][j]) cnt_1++;
                else cnt_0++;
            }
        }
        tot+=cnt_0*cnt_1;
    }
    cout<<ans-tot/2<<endl;
    return 0;
}