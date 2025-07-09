#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
map<int,ll>mp;
int main(){
    cin>>T;
    while(T--){
        mp.clear();
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            if(mp.count(a)==0) mp[a]=b;
            else mp[a]+=b;
        }
        ll sum=0;
        bool flag=true;
        for(auto i=mp.begin();i!=mp.end();i++){
            sum+=i->second;
            if(sum>1ll*k*i->first)
                flag=false; 
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}