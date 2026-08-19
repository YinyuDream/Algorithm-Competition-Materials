#include<bits/stdc++.h>
using namespace std;
int T,x,y,z;
int main(){
    cin>>T;
    while(T--){
        cin>>x>>y>>z;
        if(x==z||y==z){
            cout<<"YES"<<endl;
            continue;
        }
        if((x==0&&y!=z)||(y==0&&x!=z)||z==0){
            cout<<"NO"<<endl;
            continue;
        }
        if(z%__gcd(x,y)==0)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}