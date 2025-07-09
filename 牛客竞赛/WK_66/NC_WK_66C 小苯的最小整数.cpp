#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    set<long long> st;
    while(true){
        if(st.find(stoll(s))!=st.end()){
            break;
        }
        st.insert(stoll(s));
        s.push_back(s.front());
        s.erase(s.begin());
    }
    cout<<*st.begin()<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}