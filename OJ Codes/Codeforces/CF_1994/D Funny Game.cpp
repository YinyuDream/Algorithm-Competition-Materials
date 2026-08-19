#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int cnt=0;
    for(int i=1;i<=2000;i++)
        if(720720%i==0)
            cnt++;
    cout<<cnt<<endl;
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}