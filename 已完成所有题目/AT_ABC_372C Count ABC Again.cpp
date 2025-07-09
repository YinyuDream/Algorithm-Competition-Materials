#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int ans=0;
    for(int i=2;i<n;i++){
        if(s.substr(i-2,3)=="ABC"){
            ans++;
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        char ch;
        cin>>x>>ch;
        x--;
        if(x-2>=0&&s.substr(x-2,3)=="ABC"){
            ans--;
        }
        if(x-1>=0&&x+1<n&&s.substr(x-1,3)=="ABC"){
            ans--;
        }
        if(x<n-2&&s.substr(x,3)=="ABC"){
            ans--;
        }
        s[x]=ch;
        if(x-2>=0&&s.substr(x-2,3)=="ABC"){
            ans++;
        }
        if(x-1>=0&&x+1<n&&s.substr(x-1,3)=="ABC"){
            ans++;
        }
        if(x<n-2&&s.substr(x,3)=="ABC"){
            ans++;
        }
        cout<<ans<<endl;
    }
}