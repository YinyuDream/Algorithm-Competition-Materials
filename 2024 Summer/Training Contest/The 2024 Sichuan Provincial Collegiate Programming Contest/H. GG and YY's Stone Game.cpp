#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n%3==1){
            cout<<0<<" "<<1+(n-1)/3<<endl;
        }else if(n%3==2){
            cout<<0<<" "<<2+(n-2)/3<<endl;
        }else{
            cout<<1<<" "<<n/3<<endl;
        }
    }
}