#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int la=0,ra=n-1,lb=0,rb=n-1;
    for(int i=0;i<n;i++){
        if(a[la]!=b[lb]&&a[la]!=b[rb]){
            cout<<"Alice"<<endl;
            return;
        }
        if(a[ra]!=b[lb]&&a[ra]!=b[rb]){
            cout<<"Alice"<<endl;
            return;
        }
        if(a[la]==b[lb]){
            la++;
            lb++;
        }else if(a[la]==b[rb]){
            la++;
            rb--;
        }else if(a[ra]==b[lb]){
            ra--;
            lb++;
        }else if(a[ra]==b[rb]){
            ra--;
            rb--;
        }
    }
    cout<<"Bob"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}