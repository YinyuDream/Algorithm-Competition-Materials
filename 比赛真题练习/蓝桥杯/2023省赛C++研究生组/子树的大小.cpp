#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,m,k;
ll pw[51];
int main(){
    pw[0]=1;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(ll i=1;pw[i-1]<=1e12;i++)
            pw[i]=pw[i-1]*m;
        ll layer=1;
        for(ll i=1;i<=30;i++){
            if((pw[i]-1)/(m-1)>=k){
                layer=i;
                break;
            }
        }
        ll dep=1;
        for(ll i=1;i<=30;i++){
            if((pw[i]-1)/(m-1)>=n){
                dep=i-1;
                break;
            }
        }
        if(layer>dep){
            cout<<1<<endl;
            continue;
        }
        ll ans=(pw[dep-layer+1]-1)/(m-1);
        ll tot=k-(pw[layer-1]-1)/(m-1);
        ll rem=n-(pw[dep]-1)/(m-1);
        ll num_leaf=(tot-1)*pw[dep-layer];
        rem-=num_leaf*m;
        ans+=min(max(rem,0ll),m*pw[dep-layer]);
        cout<<ans<<endl;
    }
    return 0;
}