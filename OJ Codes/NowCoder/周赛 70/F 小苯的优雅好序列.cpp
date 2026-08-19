#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    n=a.erase(unique(a.begin(),a.end()),a.end())-a.begin();
    if(n==1){
        cout<<k<<" "<<1ll*k*(k+1)/2<<endl;
        return;
    }
    map<int,int> mp;
    for(int i=0;i<n-1;i++){
        set<int> ans;
        int d=a[i+1]-a[i];
        for(int j=1;j*j<=d;j++){
            if(d%j==0){
                if(d/j-a[i]>0&&d/j-a[i]<=k){
                    ans.insert(d/j-a[i]);
                }
                if(j-a[i]>0&&j-a[i]<=k){
                    ans.insert(j-a[i]);
                }
            }
        }
        for(auto x:ans){
            mp[x]++;
        }
    }
    int tot=0;
    ll sum=0;
    for(auto [x,y]:mp){
        if(y==n-1){
            tot++;
            sum+=x;
        }
    }
    cout<<tot<<" "<<sum<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}