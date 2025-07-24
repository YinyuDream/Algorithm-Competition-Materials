#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,x,y;
int main(){
    cin>>T;
    while(T--){
        cin>>x>>y;
        x^=y;
        int ans=1;
        while(x){
            if(x&1) break;
            x>>=1;
            ans<<=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}