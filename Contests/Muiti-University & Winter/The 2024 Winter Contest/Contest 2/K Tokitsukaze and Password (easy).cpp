#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll y;
    cin>>y;
    int ans=0;
    int pos=s.find('_')!=s.npos?s.find('_'):-1;
    set<ll> st;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    if(i==j||i==k||i==l||j==k||j==l||k==l){
                        continue;
                    }
                    string t=s;
                    for(auto &x:t){
                        if(x=='a'){
                            x=i+'0';
                        }
                        if(x=='b'){
                            x=j+'0';
                        }
                        if(x=='c'){
                            x=k+'0';
                        }
                        if(x=='d'){
                            x=l+'0';
                        }
                    }
                    if(pos==-1){
                        if(t[0]=='0'&&t.size()>1){
                            continue;
                        }
                        ll x=stoll(t);
                        if(x%8==0&&x<=y){
                            st.insert(x);
                        }
                    }else{
                        for(char ch='0';ch<='9';ch++){
                            t[pos]=ch;
                            if(t[0]=='0'&&t.size()>1){
                                continue;
                            }
                            ll x=stoll(t);
                            if(x%8==0&&x<=y){
                                st.insert(x);
                            }
                        }
                    }
                }        
            }
        }
    }
    cout<<st.size()<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}