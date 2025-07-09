#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n+1;i++)
            cin>>b[i];
        ll sum=0;
        for(int i=1;i<=n;i++)
            sum+=abs(a[i]-b[i]);
        ll ans=1e18;
        for(int i=1;i<=n;i++){
            int mn=min(a[i],b[i]);
            int mx=max(a[i],b[i]);
            int val=abs(a[i]-b[i])+1;
            if(b[n+1]>mx){
                val+=b[n+1]-mx;
            }
            if(b[n+1]<mn){
                val+=mn-b[n+1];
            }
            ans=min(ans,sum-abs(a[i]-b[i])+val);
        }
        cout<<ans<<endl;
    }
    return 0;
}