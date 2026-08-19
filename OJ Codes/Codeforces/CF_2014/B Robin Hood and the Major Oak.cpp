#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    int l=n-k+1,r=n;
    if(l%2==0){
        l++;
    }
    if(r%2==0){
        r--;
    }
    int ans=0;
    if(l<=r){
        ans=(r-l)/2+1;
    }
    if(ans%2==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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