#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a,b,c,n,ans;
int x[maxn];
map<int,int>mp;
int main(){
    cin>>a>>b>>c>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(mp.find(x[i])==mp.end())
            mp.insert(make_pair(x[i],1));
        else mp[x[i]]++;
    }
    for(auto i:mp)
        if(i.first>b&&i.first<c)
            ans+=i.second;
    cout<<ans<<endl;
    return 0;
}