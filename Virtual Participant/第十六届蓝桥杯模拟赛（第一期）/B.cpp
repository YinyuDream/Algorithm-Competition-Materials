#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=2024,ans=0;
    while(x>1){
        x=sqrt(x);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}