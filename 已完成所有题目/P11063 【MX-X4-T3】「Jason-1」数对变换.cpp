#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll _a=a,_b=b;
    if(a*b<c*d){
        cout<<-1<<endl;
        return;
    }

    vector<pair<int,ll>> ans;
    ans.push_back({1,a});
    b*=a,a=1;
    ans.push_back({2,c});
    a=c,b/=c;
    bool flag=true;
    if(b>=d){
        while(d<b/2+1){
            ans.push_back({2,b/2+1});
            ans.push_back({1,b/2+1});
            b=b/2+1;
            if(ans.size()>65){
                flag=false;
                break;
            }
        }
    }else{
        flag=false;
    }
    if(flag==true){
        if(b!=d){
            ans.push_back({2,d});
            ans.push_back({1,d});
            b=d;
        }
        if(ans.size()<=65&&flag){
            cout<<ans.size()<<endl;
            for(auto [x,y]:ans){
                cout<<x<<" "<<y<<endl;
            }
            return;
        }
    }
    ans.clear();
    a=_a,b=_b;
    ans.push_back({2,b});
    a*=b,b=1;
    ans.push_back({1,d});
    b=d,a/=d;
    if(a<c){
        cout<<-1<<endl;
        return;
    }
    while(c<a/2+1){
        ans.push_back({1,a/2+1});
        ans.push_back({2,a/2+1});
        a=a/2+1;
        if(ans.size()>65){
            cout<<-1<<endl;
            return;
        }
    }
    if(a!=c){
        ans.push_back({1,c});
        ans.push_back({2,c});
        a=c;
    }
    if(ans.size()<=65&&flag){
        cout<<ans.size()<<endl;
        for(auto [x,y]:ans){
            cout<<x<<" "<<y<<endl;
        }
        return;
    }
    cout<<-1<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}