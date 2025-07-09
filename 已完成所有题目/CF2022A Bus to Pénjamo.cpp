#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,r;
    cin>>n>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<array<int,2>> dp(r);
    int ans=0,tot=0;
    for(int i=0;i<n;i++){
        int val=a[i]/2;
        a[i]%=2;
        while(val>0){
            dp[ans][0]=i;
            dp[ans][1]=i;
            val--;
            ans++;
            tot+=2;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]&&ans<r){
            dp[ans][0]=i;
            ans++;
            a[i]=0;
            tot++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]){
            tot--;
            ans--;
            dp[ans][1]=i;
        }
    }
    cout<<tot<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}