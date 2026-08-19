#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,a,b;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        cout<<2*(a-b)<<endl;
        for(int i=b;i<=a;i++)
            cout<<i<<" ";
        for(int i=a-1;i>b;i--)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}