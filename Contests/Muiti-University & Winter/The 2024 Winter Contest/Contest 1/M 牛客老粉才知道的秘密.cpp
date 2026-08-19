#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n%6==0){
            cout<<n/6<<endl;
        }else{
            cout<<2*(n/6+1)-2<<endl;
        }
    }
    return 0;
}