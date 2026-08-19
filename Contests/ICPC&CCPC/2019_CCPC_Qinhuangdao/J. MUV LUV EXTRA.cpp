#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            s=s.substr(i+1,n);
        }
    }
    reverse(s.begin(),s.end());
    n=s.size();
    vector<int> nxt(n);
    auto get_nxt=[&](){
        for(int i=1,j=0;i<n;i++){
            while(j&&s[i]!=s[j]){
                j=nxt[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            nxt[i]=j;
        }
    };
    get_nxt();
    ll ans=-1e18;
    for(int i=0;i<n;i++){
        int len=i+1-nxt[i];
        ans=max(ans,(a*(i+1)-b*len));
    }
    cout<<ans<<endl;
    return 0;
}