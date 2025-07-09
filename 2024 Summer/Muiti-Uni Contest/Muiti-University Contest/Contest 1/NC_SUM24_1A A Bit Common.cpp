#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
int n,m;
ll mod,C[maxn][maxn];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
    cin>>n>>m>>mod;
    for(int i=0;i<maxn;i++)C[i][0]=1;
    for(int i=1;i<maxn;i++){
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=ksm(2,(m-1)*(n-i))*ksm((ksm(2,i)-1),m-1)%mod*C[n][i]%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}