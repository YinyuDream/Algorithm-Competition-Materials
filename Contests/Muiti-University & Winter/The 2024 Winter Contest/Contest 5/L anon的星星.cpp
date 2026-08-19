#include<bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    cin>>n>>x;
    for(int i=0;i<=n;i++){
        if(i-(n-i)==x){
            cout<<i<<" "<<n-i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}