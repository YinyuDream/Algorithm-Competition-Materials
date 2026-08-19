#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n*2);
    for(int i=0;i<n*2;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int cnt=unique(a.begin(),a.end())-a.begin();
    if(cnt!=n*2){
        cout<<"Qingyu"<<endl;
    }else{
        cout<<"Kevin"<<endl;
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
