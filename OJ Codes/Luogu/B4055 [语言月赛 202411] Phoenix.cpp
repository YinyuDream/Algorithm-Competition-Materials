#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),mx(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i;i--){
        mx[i]=max(mx[i+1],a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>mx[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}