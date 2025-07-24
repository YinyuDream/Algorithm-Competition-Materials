#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n,x,p;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>p;
        p=min(n*2+1,p);
        bool ans=false;
        for(ll i=1;i<=p;i++){
            if((x+i*(i+1)/2)%n==0){
                ans=true;
                break;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}