#include<bits/stdc++.h>
using namespace std;
int main(){
    int type,a,b,c,d;
    cin>>type>>a>>b>>c>>d;
    int energy=type?max(a-c,0)+max(b-d,0):a+b;
    cout<<energy<<endl;
    return 0;
}