#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}