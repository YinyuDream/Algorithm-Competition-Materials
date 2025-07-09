#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        if(a==b)cout<<c<<endl;
        else if(a==c)cout<<b<<endl;
        else cout<<a<<endl;
    }
    return 0;
}