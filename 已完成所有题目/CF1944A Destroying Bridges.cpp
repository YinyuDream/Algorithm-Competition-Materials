#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int main(){
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n>>k;
        if(k>=n-1){
            cout<<1<<endl;
            continue;
        }
        for(int i=n-1;i;i--){
            if(k-i<0){
                break;
            }
            ans++;
            k-=i;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}