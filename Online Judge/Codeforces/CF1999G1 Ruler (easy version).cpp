#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int l=1,r=1000;
    while(l<=r){
        int mid=(l+r)>>1;
        cout<<"?"<<" "<<1<<" "<<mid<<endl;
        cout.flush();
        int x;
        cin>>x;
        if(x==mid)l=mid+1;
        else r=mid-1;
    }
    cout<<"! "<<l<<endl;
    cout.flush();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}