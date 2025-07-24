#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=1e9;
        for(int i=1;i<n;i++)
            ans=min(ans,max(a[i],a[i+1])-1);
        cout<<ans<<endl;
    }
    return 0;
}