#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt_0=0,cnt_1=0;
    for(int i=1;i<=n;i++){
        int x,y,r;
        cin>>x>>y>>r;
        if(abs(x)>=75){
            cnt_0++;
        }else{
            cnt_1++;
        }
    }
    if(cnt_0<0.2*n){
        cout<<"buaa-noob";
    }else{
        cout<<"bit-noob";
    }
    return 0;
}