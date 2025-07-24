#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    while(a.size()>1){
        int x=a[0];
        int y=a[1];
        a.erase(a.begin());
        a.erase(a.begin());
        a.insert(a.begin(),(x+y)/2);
        
    }
    cout<<a[0]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}