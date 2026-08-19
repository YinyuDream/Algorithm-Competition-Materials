#include<bits/stdc++.h>
using namespace std;
int l,r;
int p[]={0,2,3,5,7,11,13,17,19,23};
int main(){
    cin>>l>>r;
    for(int i=1;i<=9;i++){
        for(int j=i+1;j<=9;j++){
            for(int k=j+1;k<=9;k++){
                if(p[i]*p[j]*p[k]>=l&&p[i]*p[j]*p[k]<=r){
                    cout<<p[i]*p[j]*p[k];
                    return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}