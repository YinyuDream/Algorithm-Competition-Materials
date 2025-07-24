#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int main(){
    cin>>T;
    while(T--){
        string s;
        cin>>n>>s;
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(s[i]<='z'&&s[i]>='a'&&s[i+1]<='9'&&s[i+1]>='0'){
                flag=false;
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]<='z'&&s[i]>='a'&&s[i+1]<='z'&&s[i+1]>='a'){
                if(s[i]>s[i+1]){
                    flag=false;
                    break;
                }
            }
            if(s[i]<='9'&&s[i]>='0'&&s[i+1]<='9'&&s[i+1]>='0'){
                if(s[i]>s[i+1]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}