#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),book(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    book[a[0]]=1;
    for(int i=1;i<n;i++){
        int pos=a[i];
        bool can=false;
        if(pos+1<n&&book[pos+1])
            can=true;
        if(pos-1>0&&book[pos-1])
            can=true;
        if(can){
            book[pos]=1;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl; 
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}