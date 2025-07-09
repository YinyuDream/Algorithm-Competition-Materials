#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int mx=*max_element(a.begin(),a.end());
    for(int i=1;i<=m;i++){
        char ch;
        int l,r;
        cin>>ch>>l>>r;
        if(ch=='+'){
            if(r>=mx&&l<=mx){
                mx++;
            }
        }
        if(ch=='-'){
            if(r>=mx&&l<=mx){
                mx--;
            }
        }
        cout<<mx<<" ";
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