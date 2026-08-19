#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    string s,t;
    cin>>n>>m>>s;
    s=" "+s;
    vector<int>a(m+1);
    for(int i=1;i<=m;i++)
        cin>>a[i];
    cin>>t;
    sort(t.begin(),t.end());
    int cnt=0;
    sort(a.begin()+1,a.end());
    for(int i=1;i<=m;i++){
        if(a[i]==a[i-1])
            continue;
        s[a[i]]=t[cnt++];
    }
    cout<<s.substr(1)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}