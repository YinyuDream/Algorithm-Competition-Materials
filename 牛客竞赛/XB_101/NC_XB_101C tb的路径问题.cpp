#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=3){
        cout<<2*(n-1)<<endl;
    }else{
        if(n%2==0){
            cout<<4<<endl;
        }else{
            cout<<6<<endl;
        }
    }
    return 0;
}