#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn];
map<int,int> mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(mp.find(a[i])==mp.end()) mp[a[i]]=1;
        else mp[a[i]]++;
    }
    for(auto it:mp){
        int num=it.first;
        if(it.second>num){
            if(mp.find(num+1)==mp.end())
                mp[num+1]=0;
            mp[num+1]+=mp[num]/(num+1);
            mp[num]%=num+1;
        }
    }
    int ans=0;
    for(auto it:mp){
        if(it.second!=0){
            ans=it.first;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}