#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,p=998244353;
int n,pw2[maxn];
long long ans;
map<int,int>mp;
int main(){
    cin>>n;
    pw2[0]=1;
    for(int i=1;i<=n;i++){
        pw2[i]=pw2[i-1]*2%p;
    }
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(mp.find(l)==mp.end()){
            mp.insert({l,1});
        }else{
            mp[l]++;
        }
        if(mp.find(r)==mp.end()){
            mp.insert({r,-1});
        }else{
            mp[r]--;
        }
    }
    for(auto i=next(mp.begin());i!=mp.end();i++)
        i->second+=prev(i)->second;
    for(auto i=mp.begin();i!=mp.end();i++){
        if(next(i)==mp.end())
            break;
        ans=ans+(1ll*(next(i)->first)-i->first)*(pw2[n]-pw2[n-(i->second)]);
        ans%=p;
    }
    cout<<(ans+p)%p<<endl;
    return 0;
}