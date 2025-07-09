#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=1e9+7,inv=500000004;
int n,m;
ll sum_1,sum_2,sum_3,ans;
ll a[maxn],pw2[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    pw2[0]=1;
    for(int i=1;i<=m;i++)
        pw2[i]=pw2[i-1]*2%p;
    for(int i=1;i<=n;i++){
        sum_1=(sum_1+a[i])%p;
        sum_2=(sum_2+i*a[i])%p;
        sum_3=(sum_3+(n-i+1)*a[i])%p;
    }
    for(int i=0;i<m;i++){
        ll sum_copy=(n*sum_1%p*(pw2[i]-1)%p*pw2[i]%p*inv%p+sum_3*pw2[i]%p)%p;
        ll sum_rev=(n*sum_1%p*(pw2[i]-1)%p*pw2[i]%p*inv%p+sum_2*pw2[i]%p)%p;
        ll sum_all=(sum_copy+sum_rev+n*pw2[i]%p*pw2[i]%p*sum_1%p)%p;
        ll len=(n*pw2[i+1])%p,tot=(sum_1*pw2[i+1])%p;
        ll num=(len*tot%p*(pw2[m-i-1]-1)%p*pw2[m-i-1]%p*inv%p+sum_all*pw2[m-i-1]%p)%p;
        ans=max(ans,num);
    }
    ans=max(ans,(n*sum_1%p*(pw2[m]-1)%p*pw2[m]%p*inv%p+sum_3*pw2[m]%p)%p);
    cout<<ans<<endl;
    return 0;
}