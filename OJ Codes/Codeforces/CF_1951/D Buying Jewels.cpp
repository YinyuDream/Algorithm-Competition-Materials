#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        if((k>=(n-1)/2+2&&k<=n-1)||k>n){
            cout<<"NO"<<endl;
            continue;
        }
        ll l=1,r=n,ans=0;
        bool flag=false;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(n/mid<k)r=mid-1;
            else if(n/mid>k)l=mid+1;
            else{
                flag=true;
                ans=mid;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl<<1<<endl<<ans<<endl;
            continue;
        }
        cout<<"YES"<<endl<<2<<endl<<n+1-k<<" "<<1<<endl;
    }
    return 0;
}