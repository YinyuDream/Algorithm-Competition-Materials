#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n,k;
ll ans_f=-1e18;
ll a[maxn],f[maxn];
ll sum()
{
    ll ans=-1e18;
    f[1]=a[1];
    for(int i=2;i<=n;i++){
        if(f[i-1]>0){
            f[i]=f[i-1]+a[i];
        }else{
            f[i]=a[i];
        }
        ans=max(ans,f[i]);
    }
    return ans;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==0){
        cout<<sum()<<endl;
    }else{
        for(int i=1;i<n;i++){
            swap(a[i],a[i+1]);
            ans_f=max(ans_f,sum());
            swap(a[i],a[i+1]);
        }
        cout<<ans_f<<endl;
    }
    return 0;
}