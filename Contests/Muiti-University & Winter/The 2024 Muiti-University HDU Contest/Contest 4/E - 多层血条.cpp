#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,hp,dmg;
    cin>>n>>m>>hp>>dmg;
    if(hp>=5*m){
        hp=hp%(5*m)+5*m;
    }
    string s="ABCDE";
    string ans(m,' ');
    for(int i=1;i<=hp;i++){
        ans[(i-1)%m]=s[((i-1)/m)%5];
    }
    if(dmg>=m){
        for(auto &c:ans){
            c='.';
        }
    }else{
        for(int i=hp-dmg+1;i<=hp;i++){
            ans[(i-1)%m]='.';
        }
    }
    cout<<'+';
    for(int i=0;i<m;i++){
        cout<<'-';
    }
    cout<<'+'<<endl;
    for(int i=0;i<n;i++){
        cout<<'|'<<ans<<'|'<<endl;
    }
    cout<<'+';
    for(int i=0;i<m;i++){
        cout<<'-';
    }
    cout<<'+'<<endl;
}
int main(){
    freopen("1005.in","r",stdin);
    freopen("1005_my.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}