#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    int cnt=a.erase(unique(a.begin(),a.end()),a.end())-a.begin();
    vector<int> tmp;
    int ans=0;
    for(int i=0;i<cnt;i++){
        if(tmp.empty()||tmp.back()==a[i]-1){
            tmp.push_back(a[i]);
        }else{
            vector<int> v;
            for(auto x:tmp){
                v.push_back(mp[x]);
            }
            int val=0;
            if(v.size()<k){
                for(auto x:v){
                    val+=x;
                }
                ans=max(ans,val);
            }else{
                for(int j=0;j<k;j++){
                    val+=v[j];
                }
                ans=max(ans,val);
                for(int j=1;j+k-1<v.size();j++){
                    val+=v[j+k-1]-v[j-1];
                    ans=max(ans,val);
                }
            }
            tmp.clear();
            tmp.push_back(a[i]);
        }
    }
    if(!tmp.empty()){
        vector<int> v;
        for(auto x:tmp){
            v.push_back(mp[x]);
        }
        int val=0;
        if(v.size()<k){
            for(auto x:v){
                val+=x;
            }
            ans=max(ans,val);
        }else{
            for(int j=0;j<k;j++){
                val+=v[j];
            }
            ans=max(ans,val);
            for(int j=1;j+k-1<v.size();j++){
                val+=v[j+k-1]-v[j-1];
                ans=max(ans,val);
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}