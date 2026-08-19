#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    auto ask=[&](string s){
        cout<<"? "<<s<<endl;
        cout.flush();
        int x;
        cin>>x;
        return x;
    };
    string ans;
    int x=ask("0");
    if(x==1){
        ans="0";
    }else{
        ans="1";
    }
    if(n==1){
        cout<<"! "<<ans<<endl;
        cout.flush();
        return ;
    }
    while(true){
        string t=ans+"0";
        x=ask(t);
        if(x==1){
            ans=t;
            if(ans.size()==n){
                break;
            }
        }else{
            t=ans+"1";
            x=ask(t);
            if(x==1){
                ans=t;
                if(ans.size()==n){
                    break;
                }
            }else{
                break;
            }
        }
    }
    if(ans.size()==n){
        cout<<"! "<<ans<<endl;
        cout.flush();
        return ;
    }
    while(true){
        string t="0"+ans;
        x=ask(t);
        if(x==1){
            ans=t;
            if(ans.size()==n){
                break;
            }
        }else{
            ans="1"+ans;
            if(ans.size()==n){
                break;
            }
        }
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}