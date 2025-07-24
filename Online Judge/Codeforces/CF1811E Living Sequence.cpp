#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n;
ll work(ll x)
{
    int num[20],cnt=0;
    memset(num,0,sizeof(num));
    while(x){
        num[++cnt]=x%9;
        x/=9;
    }
    for(int i=cnt;i>=1;i--){
        if(num[i]>=4) num[i]++;
    }
    ll ans=0;
    for(int i=cnt;i;i--){
        ans=ans*10+num[i];
    }
    return ans;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        cout<<work(n)<<endl;
    }
    return 0;
}