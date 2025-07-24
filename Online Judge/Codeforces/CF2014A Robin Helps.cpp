#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,now=0,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0&&now>0){
            ans++;
            now--;
        }
        if(x>=k){
            now+=x;
        }
    }
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