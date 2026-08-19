#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int q;
    cin>>q;
    ll now=0;
    multiset<ll> s;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            s.insert(now);
        }else if(op==2){
            ll x;
            cin>>x;
            now+=x;
        }else{
            ll x;
            cin>>x;
            int ans=0;
            while(s.size()&&now-*s.begin()>=x){
                s.erase(s.begin());
                ans++;
            }
            cout<<ans<<endl;
        }
    }
}