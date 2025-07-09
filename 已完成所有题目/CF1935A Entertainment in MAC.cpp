#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,l,pos;
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>s+1;
        l=strlen(s+1);
        pos=0;
        for(int i=1;i<=l;i++){
            if(s[i]!=s[l-i+1]){
                pos=i;
                break;
            }
        }
        if(pos==0){
            for(int i=1;i<=l;i++){
                cout<<s[i];
            }
        }else if(s[pos]<s[l-pos+1]){
            if(n%2==0){
                for(int i=1;i<=l;i++){
                    cout<<s[i];
                }
            }else{
                for(int i=1;i<=l;i++){
                    cout<<s[i];
                }
                for(int i=l;i;i--){
                    cout<<s[i];
                }
            }
        }else{
            if(n%2==1){
                for(int i=l;i;i--){
                    cout<<s[i];
                }
            }else{
                for(int i=l;i;i--){
                    cout<<s[i];
                }
                for(int i=1;i<=l;i++){
                    cout<<s[i];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}