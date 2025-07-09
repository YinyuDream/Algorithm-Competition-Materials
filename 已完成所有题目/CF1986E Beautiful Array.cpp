#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        mp[val%k].push_back((val-val%k)/k);
    }
    ll ans=0;
    int cnt=0;
    for(auto &it:mp){
        sort(it.second.begin(),it.second.end());
        auto &a=it.second;
        if(a.size()%2==0){
            for(int i=0;i<a.size()-1;i+=2){
                ans+=a[i+1]-a[i];
            }
        }else{
            if(a.size()==1){
                continue;
            }
            cnt++;
            vector<ll> sum_pre(a.size()),sum_suf(a.size());
            sum_pre[1]=a[1]-a[0];
            sum_suf[a.size()-2]=a[a.size()-1]-a[a.size()-2];
            for(int i=3;i<a.size()-1;i+=2){
                sum_pre[i]=sum_pre[i-2]+a[i]-a[i-1];
            }
            for(int i=a.size()-4;i>=0;i-=2){
                sum_suf[i]=sum_suf[i+2]+a[i+1]-a[i];
            }
            ll sum=min(sum_pre[a.size()-2],sum_suf[1]);
            for(int i=2;i<a.size()-1;i+=2){
                sum=min(sum,sum_pre[i-1]+sum_suf[i+1]);
            }
            ans+=sum;
        }
    }
    if(cnt>1){
        cout<<-1<<endl;
    }else if(cnt==1&&n%2==0){
        cout<<-1<<endl;
    }else if(cnt==0&&n%2==1){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}