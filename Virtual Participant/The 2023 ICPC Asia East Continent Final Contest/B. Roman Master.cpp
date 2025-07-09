#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s;
    cin>>s;
    vector<string> roman={"","I","II","III","IV","V","VI","VII","VIII"};
    map<string,int> mp;
    set<string> st;
    for(int i=1;i<=8;i++){
        st.insert(roman[i]);
        mp[roman[i]]=i;
    }
    int n=s.size();
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        int now=i;
        while(now>=0&&st.find(s.substr(now,i-now+1))!=st.end()){
            now--;
        }
        now++;
        ans.push_back(mp[s.substr(now,i-now+1)]);
        i=now;
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x;
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}