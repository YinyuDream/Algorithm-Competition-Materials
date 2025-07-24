#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    while(k>0){
        if(x==1){
            k%=y-1;
        }
        int tot=(x/y+1)*y-x;
        if(tot>k){
            x+=k;
            k=0;
        }else{
            x+=tot;
            k-=tot;
        }
        while(x%y==0)
            x/=y;
    }
    cout<<x<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}