#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n*2),cnt(n+1);
    for(int i=0;i<n*2;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int val=0;
    for(int i=1;i<=n*2;i++){
        if(cnt[i]&1){
            val++;
        }
    }
    if(val%2==0){
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