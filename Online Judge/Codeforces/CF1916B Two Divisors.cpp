#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(b%a==0)cout<<b/a*b<<endl;
        else cout<<a/__gcd(a,b)*b<<endl;
    }
    return 0;
}