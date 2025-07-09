#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        if(k<n-(n/m+(n%m!=0)))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}