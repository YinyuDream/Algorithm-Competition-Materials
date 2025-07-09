#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> pos(n+1);
    vector<ll> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>pos[i];
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        ll ans=0;
        int left=lower_bound(pos.begin()+1,pos.end(),l)-pos.begin();
        int right=upper_bound(pos.begin()+1,pos.end(),r)-pos.begin()-1;
        if(left>right){
            cout<<0<<endl;
            continue;
        }
        ans=sum[right]-sum[left-1];
        cout<<ans<<endl;
    }
    return 0;
}