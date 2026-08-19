#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=(a-100)/50;
        if(b>=34&&b<=40){
            ans++;
        }
        if(b==45){
            ans+=2;
        }
        if(c>=34&&c<=40){
            ans++;
        }
        if(c==45){
            ans+=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}