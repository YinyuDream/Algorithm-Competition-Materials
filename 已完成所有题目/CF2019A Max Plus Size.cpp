#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans_1=0,mx=0;
    for(int i=1;i<=n;i+=2){
        ans_1++;
        mx=max(mx,a[i]);
    }
    int ans_2=0,mx_2=0;
    for(int i=2;i<=n;i+=2){
        ans_2++;
        mx_2=max(mx_2,a[i]);
    }
    cout<<max(ans_1+mx,ans_2+mx_2)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}