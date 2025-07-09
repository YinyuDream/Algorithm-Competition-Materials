#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    sort(a,a+4);
    cout<<1ll*a[0]*a[2]<<endl;
    return 0;
}