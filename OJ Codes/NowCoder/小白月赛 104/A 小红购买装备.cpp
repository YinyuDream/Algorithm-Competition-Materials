#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,z,T;
    cin>>n>>x>>y>>z>>T;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int ans=x+y;
    for(int i=0;i<n;i++){
        if(T+z>=c[i]){
            ans=max(ans,a[i]+b[i]);
        }
    }
    cout<<ans;
    return 0;
}