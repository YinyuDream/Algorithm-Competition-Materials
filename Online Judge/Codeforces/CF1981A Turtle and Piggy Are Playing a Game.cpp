#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,l,r;
int pw2[31];
int main(){
    pw2[0]=1;
    for(int i=1;i<=30;i++)
        pw2[i]=pw2[i-1]*2;
    cin>>T;
    while(T--){
        cin>>l>>r;
    for(int i=30;i>=0;i--)
        if(pw2[i]>=l&&pw2[i]<=r){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}