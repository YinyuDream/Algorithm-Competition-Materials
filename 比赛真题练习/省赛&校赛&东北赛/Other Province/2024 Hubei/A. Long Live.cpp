#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int main(){
    cin>>T;
    while(T--){
        ll x,y;
        cin>>x>>y;
        cout<<1<<" "<<x*y/__gcd(x,y)/__gcd(x,y)<<endl;
    }
    return 0;
}