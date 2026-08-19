#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    if(a+b+c<=100&&b%5==0&&c%7==0&&a-b>b-c)cout<<"Yes";
    else cout<<"No";
    return 0;
}