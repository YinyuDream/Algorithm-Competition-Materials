#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,cur=160;
void solve(){
    int a,b,m;
    cin>>a>>b>>m;
    int _m=m;
    int val=a,cnt=1;
    while(val<b)
        val+=a,cnt++;
    int tot=cnt+1;
    int ans=m/val*tot;
    m%=val;
    int lsta=-a,lstb=-b;
    for(int i=0;i<=m;i++){
        if(i-lsta>=a){
            ans++;
            lsta=i;
        }
        if(i-lstb>=b){
            lsta=i;
            lstb=i;
            ans++;
        }
    }
    ans=max(ans,_m/b+2);
    cout<<cur*ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}