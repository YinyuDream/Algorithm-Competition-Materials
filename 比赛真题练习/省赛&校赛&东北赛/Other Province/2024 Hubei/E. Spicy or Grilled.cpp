#include<bits/stdc++.h>
using namespace std;
int T,n,x,a,b;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>a>>b;
        cout<<x*b+(n-x)*a<<endl;
    }
    return 0;
}