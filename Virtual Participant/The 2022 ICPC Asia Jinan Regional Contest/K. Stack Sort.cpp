#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,ans=0;
    cin>>n;
    vector<int> book(n+2),pos(n+2);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(!book[x+1]){
            book[x]=1;
            pos[x]=++ans;
        }else{
            book[x+1]=0;
            book[x]=1;
            pos[x]=pos[x+1];
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
    return 0;
}