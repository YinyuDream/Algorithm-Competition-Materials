#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    ll k,rem=0;
    cin>>n>>m>>k;
    vector<pair<ll,int>> a(n+1);
    vector<ll> ans(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
        rem+=a[i].first;
    }
    rem=k-rem;
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i].first;
    }
    auto work=[&](int x){
        int len=n-x+1,left=0;
        if(len<=m){
            left=n-m;
        }else{
            left=n-m+1;
        }
        left=max(left,1);
        ll l=0,r=rem;
        while(l<=r){
            ll mid=(l+r)>>1;
            auto check=[&](ll val){
                ll now=a[x].first+val;
                int tot=0;
                int pos=upper_bound(a.begin()+1,a.end(),make_pair(now,n+1))-a.begin();
                tot=n-pos+1;
                if(tot>=m){
                    return false;
                }
                bool flag=left<=x&&x<=pos-1;
                ll rest=sum[pos-1]-sum[left-1]-(flag?a[x].first:0);
                int len=pos-left;
                return (len-flag)*(now+1)-rest>rem-val;
            };
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        return l;
    };
    for(int i=n;i>=1;i--){
        ans[a[i].second]=work(i);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]>rem){
            ans[i]=-1;
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}