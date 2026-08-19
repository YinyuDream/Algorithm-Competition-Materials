#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll a,b;
ll lcm(ll u,ll v)
{
    return u*v/__gcd(u,v);
}
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(b%a==0){
            cout<<b<<endl;
        }else if(__gcd(a,b)!=1){
            cout<<a+b<<endl;
        }else{
            ll lim_a=sqrt(a),lim_b=sqrt(b),fac_a=0,fac_b=0;
            for(int i=2;i<=lim_a;i++){
                if(a%i==0){
                    fac_a=i;
                    break;
                }
            }
            for(int i=2;i<=lim_b;i++){
                if(b%i==0){
                    fac_b=i;
                    break;
                }
            }
            ll ans=lcm(a,b),num=0;
            if(fac_a&&fac_b)num=min(lcm(fac_a,fac_b),lcm(2,fac_a)+lcm(2,fac_b))+a+b;
            else if(fac_a&&!fac_b)num=min(lcm(fac_a,b),lcm(2,fac_a)+lcm(2,b))+a;
            else if(!fac_a&&fac_b)num=min(lcm(a,fac_b),lcm(2,a)+lcm(2,fac_b))+b;
            else num=lcm(2,a)+lcm(2,b);
            cout<<min(num,ans)<<endl;
        }
    }
    return 0;
}