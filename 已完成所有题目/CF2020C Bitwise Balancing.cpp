#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    ll b,c,d;
    cin>>b>>c>>d;
    vector<int> ans(61,-1);
    for(int i=60;i>=0;i--){
        int x=(b>>i)&1;
        int y=(c>>i)&1;
        int z=(d>>i)&1;
        if((0|x)-(0&y)==z){
            ans[i]=0;
        }
        if((1|x)-(1&y)==z){
            ans[i]=1;
        }
        if(ans[i]==-1){
            cout<<-1<<endl;
            return;
        }
    }
    ll res=0;
    for(int i=60;i>=0;i--){
        res=res*2+ans[i];
    }
    cout<<res<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}