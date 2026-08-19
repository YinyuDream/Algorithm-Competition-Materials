#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans=1e9;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        ans=1e9;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++){
            if(a[i]>a[i+1]){
                ans=min(ans,0);
            }else{
                int t=(a[i+1]-a[i])/2+1;
                ans=min(ans,t);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}