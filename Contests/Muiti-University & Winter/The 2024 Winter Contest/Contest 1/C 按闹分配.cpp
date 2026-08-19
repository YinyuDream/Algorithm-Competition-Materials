#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,Q;
    ll tc;
    cin>>n>>Q>>tc;
    vector<ll> t(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    sort(t.begin()+1,t.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+t[i];
    }
    auto check=[&](int x,ll M){
        return tc*(n-x)<=M;
    };
    while(Q--){
        ll M;
        cin>>M;
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,M))r=mid-1;
            else l=mid+1;
        }
        cout<<sum[l]+tc<<endl;
    }
    return 0;
}