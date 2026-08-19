#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll fac[maxn];
ll perm(int n,int m){
    return 1ll*fac[n]/fac[n-m];
}
signed main(){
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=1ll*fac[i-1]*i;
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n;
        for(int j=n;j<=n;j++)
        for(int i=j;i<=20;i++)
            
                ans=ans+fac[i]/fac[i-j]/j%j;
        cout<<ans<<endl;
    }   
    return 0;
}