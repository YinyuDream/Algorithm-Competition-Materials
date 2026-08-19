#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n,b,x;
ll c[maxn],sum[maxn];
vector<ll> v[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>b>>x;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            v[i].clear();
        }
        sum[n+1]=0;
        sort(c+1,c+n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c[i];j++){
                ll div=c[i]/j,rem=c[i]%j;
                v[i].push_back(rem*(rem-1)*(div+1)*(div+1)/2+(j-rem)*(j-rem-1)*div*div/2+(j-rem)*rem*div*(div+1));
            }
        }
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+v[i].back();
        ll mx=0;
        for(int i=1;i<=c[n];i++){
            int pos=upper_bound(c+1,c+n+1,i)-c;
            ll ans=sum[pos-1];
            for(int j=pos;j<=n;j++)
                ans+=v[j][i-1];
            ans=ans*b-(i-1)*x;
            mx=max(mx,ans);
        }
        cout<<mx<<endl;
    }
    return 0;
}