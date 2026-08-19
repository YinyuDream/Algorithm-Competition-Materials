#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,k,t;
    char c;
    cin>>x>>y>>k>>t>>c;
    if(c=='R'){
        cout<<k+t;
    }else{
        if(k<t){
            cout<<k+x+t;
        }else{
            cout<<t;
        }
    }
    return 0;
}