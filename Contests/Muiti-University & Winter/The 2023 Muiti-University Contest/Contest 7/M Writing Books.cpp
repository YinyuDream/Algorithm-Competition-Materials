#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,pw10[10];
int main(){
    pw10[0]=1;
    for(int i=1;i<=9;i++)
        pw10[i]=pw10[i-1]*10;
    cin>>T;
    while(T--){
        cin>>n;
        long long ans=0;
        for(int i=0;i<=9;i++)
            ans+=max(0ll,n-pw10[i]+1);
        cout<<ans<<endl;
    }
    return 0;
}