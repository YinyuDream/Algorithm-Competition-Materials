#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    int now=1;
    for(int i=k;i<=n;i+=k){
        a[i]=now++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            a[i]=now++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}