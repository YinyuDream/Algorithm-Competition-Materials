#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n+1);
    int sum=0;
    for(int i=1;i<=n*2;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum%2<<" "<<min(sum,2*n-sum)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}