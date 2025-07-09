#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=1e9+7;
int T,n,k;
ll a[maxn],sum[maxn],mn[maxn],mn_pos[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n;i++){
            if(mn[i-1]>sum[i]){
                mn[i]=sum[i];
                mn_pos[i]=i;
            }else if(mn[i-1]==sum[i]&&sum[i]>sum[mn_pos[i-1]]){
                mn[i]=sum[i];
                mn_pos[i]=i;
            }else{
                mn[i]=mn[i-1];
                mn_pos[i]=mn_pos[i-1];
            }
        }
        ll mx=0;
        int pos=0;
        for(int i=1;i<=n;i++){
            if(mx<sum[i]-sum[mn_pos[i-1]]){
                mx=sum[i]-sum[mn_pos[i-1]];
                pos=i;
            }
        }
        if(pos==0){
            cout<<(sum[n]%p+p)%p<<endl;
            continue;
        }
        ll ans=1;
        for(int i=1;i<=k;i++)
            ans=ans*2%p;
        mx%=p;
        ans=ans*mx%p;
        ans=(ans+sum[n]-sum[pos]+sum[mn_pos[pos]])%p;
        cout<<(ans+p)%p<<endl;
    }
    return 0;
}