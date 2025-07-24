#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll p=998244353;
void solve(){
    int n,w;
    cin>>n>>w;
    vector<int> a(n+1),b(n+1),pos(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=-1){
            pos[a[i]]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        int l=i,r=min(i+w,n);
        if(pos[b[i]]>r){
            cout<<0<<endl;
            return;
        }
        if(pos[b[i]]==-1){
            int cnt=0;
            for(int j=l;j<=r;j++){
                if(a[j]==-1){
                    cnt++;
                }
            }
            ans=ans*cnt%p;
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