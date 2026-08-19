#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    ll l=l1+l2,r=r1+r2;
    vector<int> low,up;
    while(l){
        low.push_back(l%10);
        l/=10;
    }
    while(r){
        up.push_back(r%10);
        r/=10;
    }
    while(low.size()<up.size()){
        low.push_back(0);
    }
    reverse(low.begin(),low.end());
    reverse(up.begin(),up.end());
    int mx=low.size(),ans=0;
    function<int(int,int)> find=[&](int now,int op){
        if(now==mx){
            return 0;
        }
        if(op==2){
            if(low[now]==up[now]){
                return find(now+1,2)+low[now];
            }
            int val=0;
            val=max(val,find(now+1,1)+low[now]);
            val=max(val,find(now+1,0)+up[now]);
            for(int i=low[now]+1;i<up[now];i++){
                val=max(val,9*(mx-now-1)+i);
            }
            return val;
        }else if(op==1){
            int val=0;
            for(int i=low[now]+1;i<=9;i++){
                val=max(val,9*(mx-now-1)+i);
            }
            val=max(val,find(now+1,1)+low[now]);
            return val;
        }else{
            int val=0;
            for(int i=0;i<up[now];i++){
                val=max(val,9*(mx-now-1)+i);
            }
            val=max(val,find(now+1,0)+up[now]);
            return val;
        }
    };
    cout<<find(0,2)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}