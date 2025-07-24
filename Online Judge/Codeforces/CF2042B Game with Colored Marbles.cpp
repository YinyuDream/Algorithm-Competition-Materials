#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),cnt(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int tot=0,all=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==1){
            tot++;
        }
        if(cnt[i]>0){
            all++;
        }
    }
    cout<<(tot+1)/2*2+(all-tot)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}