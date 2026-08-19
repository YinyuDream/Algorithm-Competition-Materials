#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long h;
    cin>>n>>h;
    while(n--){
        long long x,y,z;
        cin>>x>>y>>z;
        long long _x=x,_y=y,_z=2*h-z;
        long long gcd=__gcd(_x,__gcd(_y,_z));
        _x/=gcd,_y/=gcd,_z/=gcd;
        cout<<_x<<" "<<_y<<" "<<_z<<endl;
    }
}