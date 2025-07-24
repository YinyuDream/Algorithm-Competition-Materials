#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int x=0,y=0;
    int cycle=100;
    while(cycle--){
        for(int i=0;i<n;i++){
            if(s[i]=='E'){
                x++;
            }
            if(s[i]=='W'){
                x--;
            }
            if(s[i]=='N'){
                y++;
            }
            if(s[i]=='S'){
                y--;
            }
            if(x==a&&y==b){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;    
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}