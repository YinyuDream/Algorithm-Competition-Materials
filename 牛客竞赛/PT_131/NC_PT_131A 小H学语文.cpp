#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    ll mx=0;
    int pos=-1;
    for(int i=n-1;i>=0;i--){
        if(1ll*v[i].first*(n-i)*(n-i)>=mx){
            mx=1ll*v[i].first*(n-i)*(n-i);
            pos=i;
        }
    }
    vector<int> ans;
    for(int i=pos;i<n;i++){
        ans.push_back(v[i].second);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x+1<<" ";
    }
    return 0;
}