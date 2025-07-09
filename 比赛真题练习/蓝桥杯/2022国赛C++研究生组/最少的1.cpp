#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
typedef long long ll;
int n;
int work(ll x)
{
    int ans=0;
    while(x){
        ans+=x%2;
        x/=2;
    }
    return ans;
}
int main(){
    cin>>n;
    int ans=1e9;
    for(int i=2;i<=maxn;i++)
        ans=min(ans,work(1ll*n*i));
    cout<<ans<<endl;
    return 0;
}