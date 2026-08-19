#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>a>>b>>c;
        if(((long long)n*n*n)%2==0)
            cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}