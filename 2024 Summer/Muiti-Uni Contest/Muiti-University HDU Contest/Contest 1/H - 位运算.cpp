#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,cnt[2]={0,0};
    ll ans=1;
    cin>>n>>k;
    for(int a=0;a<=1;a++)
        for(int b=0;b<=1;b++)
            for(int c=0;c<=1;c++)
                for(int d=0;d<=1;d++)
                    cnt[((a&b)^c)|d]++;
    for(int i=0;i<k;i++){
        ans*=cnt[(n>>i)&1];
    }      
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}