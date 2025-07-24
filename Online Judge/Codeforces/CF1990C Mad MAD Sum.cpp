#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,mx=0;
    ll ans=0;
    cin>>n;
    vector<int> a(n+1),b(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
        if(pos[a[i]]==0)
            pos[a[i]]=i;
        else{
            mx=max(mx,a[i]);
        }
        b[i]=mx;
    }
    for(int i=1;i<=n;i++)
        a[i]=b[i];
    fill(b.begin(),b.end(),0);
    fill(pos.begin(),pos.end(),0);
    mx=0;
    for(int i=1;i<=n;i++){
        ans+=a[i];
        if(pos[a[i]]==0){
            pos[a[i]]=i;
        }else{
            mx=max(mx,a[i]);
        }
        b[i]=mx;
    }
    for(int i=1;i<=n;i++)
        ans+=1ll*b[i]*(n-i+1);
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