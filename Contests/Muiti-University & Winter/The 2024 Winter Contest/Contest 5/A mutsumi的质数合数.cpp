#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
int main(){
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a==1){
            ans--;
        }
    }
    cout<<ans;
    return 0;
}