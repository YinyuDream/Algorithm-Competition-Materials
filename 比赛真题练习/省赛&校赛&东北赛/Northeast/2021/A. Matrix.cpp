#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10,p=998244353;
int T,n;
int ksm(ll a,int b)
{
    if(b==0)return 1;
    int ans=ksm(a,b/2);
    ans=1ll*ans*ans%p;
    if(b&1)ans=1ll*ans*a%p;
    return ans;
}
int fac[maxn*maxn];
int perm(int a,int b)
{
    if(a<b)return 0;
    return 1ll*fac[a]*ksm(fac[a-b],p-2)%p;
}
void work()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+1ll*perm(n*n-n,i-1)*perm(n*n-i,n-i)%p)%p;
    ans=(ans+p)%p;
    cout<<1ll*ans*fac[n*n-n]%p*n*n%p<<endl;
}
int main(){
    fac[0]=1;
    for(int i=1;i<maxn*maxn;i++)
        fac[i]=1ll*fac[i-1]*i%p;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}