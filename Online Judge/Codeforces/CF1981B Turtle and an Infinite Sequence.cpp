#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int l=max(n-m,0),r=n+m;
        int ans=0;
        for(int i=30;i>=0;i--){
            if((l&(1<<i))==(r&(1<<i))){
                ans|=l&(1<<i);
            }else{
                ans+=(1<<i+1)-1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}