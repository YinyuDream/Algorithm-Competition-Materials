#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<ll> sum(n+1);
    string s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    cin>>s;
    s=" "+s;
    function<ll(int,int)> get=[&](int l,int r){
        if(l>=r)
            return 0ll;
        int nl=l,nr=r;
        while(nl<r&&s[nl]!='L')
            nl++;
        while(nr>l&&s[nr]!='R')
            nr--;
        if(nl>=nr)
            return 0ll;
        return sum[nr]-sum[nl-1]+get(nl+1,nr-1);
    };
    cout<<get(1,n)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}