#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(i-(n-i)==m){
                cout<<"Yes"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"No"<<endl;
    }
    return 0;
}