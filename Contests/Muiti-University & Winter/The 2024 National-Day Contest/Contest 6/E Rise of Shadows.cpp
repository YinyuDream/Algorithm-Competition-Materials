#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    bool is_run=false;
    if((n%4==0&&n%100!=0)||n%400==0)
        is_run=true;
    int lim=sqrt(n);
    bool is_prime=true;
    for(int i=2;i<=lim;i++){
        if(n%i==0){
            is_prime=false;
            break;
        }
    }
    if(is_prime&&is_run){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}