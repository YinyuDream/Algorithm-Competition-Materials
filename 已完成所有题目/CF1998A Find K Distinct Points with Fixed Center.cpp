#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int xc,yc,k;
    cin>>xc>>yc>>k;
    if(k&1){
        for(int i=xc-k/2;i<=xc+k/2;i++){
            cout<<i<<" "<<yc<<endl;
        }
    }else{
        for(int i=xc-k/2;i<=xc+k/2;i++){
            if(i==xc) continue;
            cout<<i<<" "<<yc<<endl;
        }
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