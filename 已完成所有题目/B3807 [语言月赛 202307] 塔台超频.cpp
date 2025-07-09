#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans;
int a[maxn],b[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]>b[i-1]){
            ans=max(ans,a[i]-a[i-1]-b[i-1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}