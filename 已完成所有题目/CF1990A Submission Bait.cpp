#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    bool flag=false;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=a[j]==a[i];
        }
        if(cnt%2==1)
            flag=true;
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}