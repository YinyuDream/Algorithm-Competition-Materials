#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> seg(m);
    for(int i=0;i<m;i++){
        cin>>seg[i].first>>seg[i].second;
    }
    sort(seg.begin(),seg.end());
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<seg[i].first<<" "<<seg[(i+m-1)%m].second<<endl;
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