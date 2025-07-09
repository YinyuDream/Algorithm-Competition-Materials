#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),f(n+1),g(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]>a[i]){
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        g[i]=1;
        for(int j=n;j>i;j--){
            if(a[j]>a[i]){
                g[i]=max(g[i],g[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]+g[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}