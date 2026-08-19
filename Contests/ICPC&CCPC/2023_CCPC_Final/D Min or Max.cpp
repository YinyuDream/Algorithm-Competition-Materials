#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int now=-1;
    for(int i=0;i<m;i++){
        now++;
        while(now<n&&a[now]!=b[i]){
            now++;
        }
    }
    if(now>=n){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}