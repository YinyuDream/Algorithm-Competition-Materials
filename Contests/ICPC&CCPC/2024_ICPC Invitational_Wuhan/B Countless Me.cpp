#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,sum;
int main(){
    cin>>n;
    for(int i=1,u;i<=n;i++)
        cin>>u,sum+=u;
    for(int i=30;i>=0;i--){
        if(n*((1ll<<i)-1)>=sum){
            ans=ans*2;
        }else{
            int cnt=0;
            while(sum-(1ll<<i)>=0&&cnt<n)
                sum-=(1ll<<i),cnt++;
            ans=ans*2+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}