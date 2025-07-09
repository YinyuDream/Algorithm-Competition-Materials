#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    int ans=0;
    while(n){
        ans=max(ans,int(n%10));
        n/=10;
    }
    cout<<ans<<endl;
    return 0;
}