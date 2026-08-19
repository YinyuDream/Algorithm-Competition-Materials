#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=310;
const ll p=1000003;
int n;
ll a[maxn],sum[maxn],inv[maxn],f[maxn][maxn];
ll ksm(ll a,ll b)
{
    if(b==0)return 1;
    ll ans=ksm(a,b/2);
    ans=ans*ans%p;
    if(b&1)
        ans=ans*a%p;
    return ans;
}
ll query(int l,int r)
{
    return sum[r]*inv[l-1]%p;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sum[0]=inv[0]=1;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]*a[i]%p;
        inv[i]=ksm(sum[i],p-2);
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            for(int i=l;i<l+len-1;i++){
                ll ans=query(l,i)-query(i+1,l+len-1);
                f[l][l+len-1]=max(f[l][l+len-1],f[l][i]+f[i+1][l+len-1]+ans*ans);
            }
        }
    }
    cout<<f[1][n];
    return 0;
}