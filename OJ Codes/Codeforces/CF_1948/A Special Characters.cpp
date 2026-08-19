#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n%2==0){
            cout<<"YES"<<endl;
            n/=2;
            for(int i=1;i<=n;i++)
                if(i%2==1) cout<<"AA";
                else cout<<"BB";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}