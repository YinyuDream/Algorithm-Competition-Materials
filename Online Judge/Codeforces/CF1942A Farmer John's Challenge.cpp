#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        if(n==k){
            for(int i=1;i<=n;i++)
                cout<<1<<" ";
        }else if(k==1){
            for(int i=1;i<=n;i++)
                cout<<i<<" ";
        }else cout<<-1;
        cout<<endl;
    }
    return 0;
}