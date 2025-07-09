#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),lst(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0,tot=0;
    for(int i=1;i<=n;i++){
        tot+=i-lst[a[i]];
        ans+=tot;
        lst[a[i]]=i;
    }
    cout<<ans<<endl;
    return 0;
}