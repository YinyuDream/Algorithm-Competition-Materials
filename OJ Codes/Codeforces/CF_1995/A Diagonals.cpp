#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    if(k==0){
        cout<<0<<endl;
    }else if(k<=n){
        cout<<1<<endl;
    }else{
        int ans=1,val=n-1;
        k-=n;
        while(k>0){
            k-=val;
            ans++;
            if(k<=0){
                cout<<ans<<endl;
                return;
            }
            k-=val;
            ans++;
            val--;
        }
        cout<<ans<<endl;
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