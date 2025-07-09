#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x){
    if(x<2){
        return false;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int x=2024,ans=0;
    for(int i=1;i<=2024;i++){
        if(x%i==0&&is_prime(i)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}