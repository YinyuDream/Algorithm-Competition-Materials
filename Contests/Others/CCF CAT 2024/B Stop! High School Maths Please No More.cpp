#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    map<ll,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=n-1;
    for(auto x:mp){
        ans=min(ans,n-x.second);
    }
    auto check=[&](int i,int j)->ll{
        if(a[j]%a[i]!=0||a[i]>a[j]){
            return 0;
        }
        ll x=a[j]/a[i];
        ll y=pow(x,1.0/(j-i));
        for(ll k=max(1ll,y-5);k<=y+5;k++){
            ll cur=1;
            for(int _=0;_<j-i;_++){
                cur*=k;
            }
            if(cur==x){
                return k;
            }
        }
        return 0;
    };
    for(int i=0;i<min(n,60);i++){
        for(int j=i+1;j<min(n,60);j++){
            i128 q=check(i,j);
            if(!q){
                continue;
            }
            bool go_zero=false;
            int cnt=0;
            i128 cur=a[i];
            for(int k=i-1;k>=0;k--){
                cur/=q;
                if(cur!=a[k])
                    cnt++;
                if(cur==0){
                    go_zero=true;
                    break;
                }
            }
            if(go_zero){
                continue;
            }
            cur=a[i];
            bool flag=true;
            for(int k=i+1;k<n;k++){
                cur*=q;
                if(cur!=a[k])
                    cnt++;
                if(cur>__int128(1e18)){
                    ans=min(ans,cnt+n-1-k);
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans=min(ans,cnt);
            }
        }
    }
    cout<<ans;
    return 0;
}