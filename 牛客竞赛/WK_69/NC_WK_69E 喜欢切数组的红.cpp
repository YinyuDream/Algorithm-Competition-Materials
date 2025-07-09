#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll sum=accumulate(a.begin()+1,a.end(),0ll);
    if(sum%3!=0){
        cout<<0<<endl;
        return 0;
    }
    sum/=3;
    vector<ll> pre_sum(n+1),suf_sum(n+1);
    vector<vector<ll>> mx(n+1,vector<ll>(20));
    for(int i=1;i<=n;i++){
        pre_sum[i]=pre_sum[i-1]+a[i];
        mx[i][0]=a[i];
    }
    for(int j=1;j<20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        }
    }
    suf_sum[n]=a[n];
    for(int i=n-1;i>=1;i--){
        suf_sum[i]=suf_sum[i+1]+a[i];
    }
    auto query=[&](int l,int r){
        int k=31-__builtin_clz(r-l+1);
        return max(mx[l][k],mx[r-(1<<k)+1][k]);
    };
    vector<int> can_suf(n+1),can_pre(n+1),sum_suf(n+1);
    for(int i=1;i<=n;i++){
        if(query(1,i)>0&&pre_sum[i]==sum)
            can_pre[i]=1;
        if(query(i,n)>0&&suf_sum[i]==sum)
            can_suf[i]=1;
    }
    sum_suf[n]=can_suf[n];
    for(int i=n-1;i>=1;i--){
        sum_suf[i]=sum_suf[i+1]+can_suf[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(can_pre[i]){
            int l=i+1,r=n;
            while(l<=r){
                int mid=(l+r)>>1;
                if(query(i+1,mid)>0){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            if(l+1<=n){
                ans+=sum_suf[l+1];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}