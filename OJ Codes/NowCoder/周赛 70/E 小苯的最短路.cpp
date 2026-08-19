#include<bits/stdc++.h>
using namespace std;
int sum_xor(int x){
    if(x%4==0){
        return x;
    }
    if(x%4==1){
        return 1;
    }
    if(x%4==2){
        return x+1;
    }
    return 0;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n%2==0){
            cout<<sum_xor(n)<<endl;
        }else{
            cout<<(sum_xor(n)^1)<<endl;
        }
    }
    return 0;
}