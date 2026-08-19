#include<bits/stdc++.h>
using namespace std;
void solve(){
    int m,n;
    cin>>n>>m;
    vector<int> v(n),w(n);
    for(int i=0;i<n;i++){
        cin>>v[i]>>w[i];
    }
    auto work=[&](int pos){
        int val=m;
        if(pos!=-1){
            val^=(1<<pos);
            val|=(1<<pos)-1;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            bool can=true;
            for(int j=0;j<=30;j++){
                if(((val>>j)&1)==0&&((w[i]>>j)&1)==1){
                    can=false;
                }
            }
            if(can){
                ans+=v[i];
            }
        }
        return ans;
    };
    long long ans=work(-1);
    for(int i=0;i<=30;i++){
        if((m>>i)&1){
            ans=max(ans,work(i));
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}