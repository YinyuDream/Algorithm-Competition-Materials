#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),book(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        book[a[i]]++;
    }
    int ans=n;
    for(int i=0;i<n;i++)
        ans=min(ans,n-book[a[i]]);
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