#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    if(d==1){
        cout<<1ll*sum*(sum-1)/2<<endl;
        return;
    }
    if(d==2){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=1ll*a[i]*(sum-a[i]);
        }
        cout<<ans/2<<endl;
        return;
    }
    sort(a.begin()+1,a.end());
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]){
            int len=n-i+1,val=a[i]-a[i-1];
            ans+=1ll*val*len*(len-1)/2;
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