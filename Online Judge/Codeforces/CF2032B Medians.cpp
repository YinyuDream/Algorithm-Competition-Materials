#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        cout<<1<<endl<<1<<endl;
        return;
    }
    if(k==1||k==n){
        cout<<-1<<endl;
        return;
    }
    if(k==n/2+1){
        cout<<1<<endl<<1<<endl;
    }else if(k<n/2+1){
        cout<<3<<endl;
        cout<<1<<" "<<2<<" "<<k*2-1<<endl;
    }else{
        cout<<3<<endl;
        cout<<1<<" "<<k*2-(n-1)<<" "<<n<<endl;
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