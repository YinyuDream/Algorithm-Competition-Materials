#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,C,ans=0;
    cin>>n>>C;
    int szC=to_string(C).size();
    for(int i=0;i<=C;i++){
        int szA=to_string(i).size();
        int szB=to_string(C-i).size();
        if(szA+szB+szC+2==n){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}