#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i];
        ll gcd=a[1]*b[1],lcm=b[1];
        int ans=0;
        for(int i=1;i<=n;i++){
            gcd=__gcd(gcd,a[i]*b[i]),lcm=lcm*b[i]/__gcd(lcm,b[i]);
           if(gcd%lcm!=0){
                gcd=a[i]*b[i];
                lcm=b[i];
                ans++;
           }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}