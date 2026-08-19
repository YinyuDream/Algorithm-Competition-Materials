#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int p=998244353;
int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=1ll*ans*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    cout<<ksm(2,n-(n%3==2))<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}