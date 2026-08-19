#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,a,b,c,d;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        if(a==0){
            cout<<1<<endl;
            continue;
        }
        int ans=a+min(b,c)*2,los=max(b,c)-min(b,c);
        if(los+d<=a+1)
            ans+=los+d;
        else
            ans+=a+1;
        cout<<ans<<endl;
    }
    return 0;
}