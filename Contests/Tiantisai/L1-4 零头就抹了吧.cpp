#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int pos=-1;
    for(int i=0;i<=31;i++){
        if(n&(1<<i)){
            pos=i;
        }
    }
    for(int i=pos-1;i>=0;i--){
        if(n&(1<<i)){
            n^=(1<<i);
        }
    }
    cout<<n;
    return 0;
}