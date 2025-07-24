#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+2),b(n);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin()+1,a.end()-1);
    for(int i=1;i<n;i++){
        b[i]=a[i]+a[i+1];
    }
    int ans=n-1;
    for(int i=n;i>=2;i--){
        if(a[i]==a[i+1]){
            continue;
        }
        int val=n-i;
        int pos=upper_bound(b.begin()+1,b.end(),a[i])-b.begin();
        val+=pos-1;
        ans=min(ans,val);
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