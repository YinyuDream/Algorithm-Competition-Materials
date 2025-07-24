#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        string s;
        cin>>s;
        n=s.size();
        int pos=n;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=s[n-1]){
                pos=i;
                break;
            }
        }
        pos++;
        for(int i=pos;i>=0;i--){
            pos-=k;
            for(int j=pos;j<i;j++){
                if(s[])
            }
        }
    }
    return 0;
}