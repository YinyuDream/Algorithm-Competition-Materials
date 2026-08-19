#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),suf(n+1),pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=max(pre[i-1],a[i]);
    }
    suf[n]=a[n];
    for(int i=n-1;i;i--){
        suf[i]=max(suf[i+1],a[i]);
    }
    if(n==1){
        cout<<a[1]<<endl;
        return;
    }
    int len=max(2,n-k),ans=0;
    for(int i=1;i+len-1<=n;i++){
        ans=max(ans,suf[i+len-1]+pre[i]);
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