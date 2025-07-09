#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int nx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void solve(){
    int n,x=0,y=0,face=0;
    string s;
    cin>>n>>s;
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            face=face-1;
            if(face==-1) face=3;
            if(st.count({x,y})){
                cout<<-1<<endl;
                return;
            }
            st.insert({x,y});
            x+=nx[face][0];
            y+=nx[face][1];
        }else if(s[i]=='R'){
            face=(face+1)%4;
            if(st.count({x,y})){
                cout<<-1<<endl;
                return;
            }
            st.insert({x,y});
            x+=nx[face][0];
            y+=nx[face][1];
        }else{
            if(st.count({x,y})){
                cout<<-1<<endl;
                return;
            }
            st.insert({x,y});
            x+=nx[face][0];
            y+=nx[face][1];
        }
    }
    if(x||y||face){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
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