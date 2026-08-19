#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void solve(){
    int n,x,y;
    string s;
    cin>>n>>x>>y>>s;
    vector<pii>sum(n+1);
    map<pii,vector<int>>mp;
    for(int i=0;i<n;i++){
        if(s[i]=='W'){
            sum[i+1].first=sum[i].first;
            sum[i+1].second=sum[i].second+1;
        }
        if(s[i]=='D'){
            sum[i+1].first=sum[i].first+1;
            sum[i+1].second=sum[i].second;
        }
        if(s[i]=='S'){
            sum[i+1].first=sum[i].first;
            sum[i+1].second=sum[i].second-1;
        }
        if(s[i]=='A'){
            sum[i+1].first=sum[i].first-1;
            sum[i+1].second=sum[i].second;
        }
    }
    //for(int i=0;i<=n;i++){
    //    cout<<sum[i].first<<" "<<sum[i].second<<endl;
    //}
    for(int i=0;i<=n;i++){
        if(mp.find(sum[i])==mp.end()){
            mp[sum[i]]=vector<int>(1,i);
        }
        else{
            mp[sum[i]].push_back(i);
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int nx=x+sum[i].first,ny=y+sum[i].second;
        pii p=make_pair(nx,ny);
        if(mp.find(p)==mp.end())
            continue;
        auto it=lower_bound(mp[p].begin(),mp[p].end(),i);
        if(it!=mp[p].end())
            ans+=n-(*it)+1;
        //cout<<i<<" "<<n-(*it)+1<<endl;
    }
    if(!x&&!y)
        ans-=n;
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}