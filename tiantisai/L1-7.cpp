#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[31][1<<16];
map<ll,pair<int,int>> mp;
ll qpow(ll a,int b){
    if(b==0)return 1;
    ll ans=qpow(a,b/2);
    ans=ans*ans;
    if(b&1)ans=ans*a;
    return ans;
}
int main(){
    for(int i=1;i<=30;i++){
        sum[i][1]=1;
        for(int j=2;j;j++){
            sum[i][j]=sum[i][j-1]+qpow(j,i);
            mp[sum[i][j]]=make_pair(i,j);
            //cout<<sum[i][j]<<endl;
            if(sum[i][j]>(1ll<<31)){
                break;
            }
        }
    }
    ll n;
    cin>>n;
    if(mp.find(n)==mp.end()){
        cout<<"Impossible for "<<n<<".";
    }else{
        pair<int,int> ans=mp[n];
        auto [x,y]=ans;
        for(int i=1;i<y;i++){
            cout<<i<<"^"<<x<<"+";
        }
        cout<<y<<"^"<<x;
    }
}