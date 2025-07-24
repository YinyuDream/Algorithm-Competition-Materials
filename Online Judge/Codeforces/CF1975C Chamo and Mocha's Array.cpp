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
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0;
        for(int i=1;i<n;i++)
            ans=max(ans,min(a[i],a[i+1]));
        for(int i=1;i<n-1;i++){
            int b[3]={a[i],a[i+1],a[i+2]};
            sort(b,b+3);
            ans=max(ans,b[1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}