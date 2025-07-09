#include<bits/stdc++.h>
using namespace std;
int n,T;
int main(){
    cin>>n>>T;
    for(int i=n;i>1;i--)
        cout<<i<<" "<<i-1<<endl;
    cout<<1<<" "<<n;
    return 0;
}