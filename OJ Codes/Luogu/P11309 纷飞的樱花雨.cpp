#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1),mx(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    if(k==0){
        cout<<accumulate(mx.begin()+1,mx.end(),0ll)<<endl;
    }else{
        if(n>2){
            cout<<*max_element(a.begin()+1,a.end())*n<<endl;
        }else{
            if(k&1){
                swap(a[1],a[2]);
            }
            cout<<a[1]+max(a[1],a[2])<<endl;
        }
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