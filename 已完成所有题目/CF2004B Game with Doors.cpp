#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if(r1>r2){
        swap(l1,l2);
        swap(r1,r2);
    }
    if(r1<l2){
        cout<<1<<endl;
    }else{
        cout<<r1-max(l1,l2)+2-(l1==l2)-(r1==r2)<<endl;
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