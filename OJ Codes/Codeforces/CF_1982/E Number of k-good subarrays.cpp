#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    auto bit=[&](int x){
        int res=0;
        for(int i=0;i<31;i++){
            if(x&(1<<i)){
                res++;
            }
        }
        return res;
    };
    for(int i=0;i<n;i++){
        if(bit(i)==1)
            cout<<endl<<i<<" ";
        cout<<(bit(i)>3)<<" ";
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