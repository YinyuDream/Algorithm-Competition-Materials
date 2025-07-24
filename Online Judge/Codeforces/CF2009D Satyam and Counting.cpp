#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,sum=0;
    ll ans=0;
    cin>>n;
    vector<int> cnt(n+1,0),book_0(n+1),book_1(n+1);
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        cnt[x]++;
        sum++;
        if(y==0){
            book_0[x]++;
        }
        else{
            book_1[x]++;
        }
    }
    for(int i=0;i<=n;i++){
        if(cnt[i]==2){
            ans+=sum-2;
        }
    }
    for(int i=0;i+2<=n;i++){
        ans+=book_0[i]&&book_0[i+2]&&book_1[i+1];
        ans+=book_1[i]&&book_1[i+2]&&book_0[i+1];
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