#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    if(k==n){
        for(int i=1;i<=n;i++){
            cout<<1<<" ";
        }
        return 0;
    }
    for(int i=1;i<=k+1;i++){
        cout<<(i&1)<<" ";
    }
    for(int i=k+2;i<=n;i++){
        cout<<((k+1)&1)<<" ";
    }
    return 0;
}