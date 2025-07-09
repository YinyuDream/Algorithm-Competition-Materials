#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans,a[maxn];
char s[maxn];
int main(){
    cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'1';
    for(int i=2;i<=n;i++){
        bool book=0;
        for(int len=1;i-len>=1&&i+len<=n;len++){
            if(a[i-len]>a[i+len]){
                ans++;
                book=1;
            }else if(a[i-len]==a[i+len]){
                if(book==1){
                    ans++;
                }
            }else{
                book=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        bool book=0;
        for(int len=0;i-len-1>=1&&i+len<=n;len++){
            if(a[i-len-1]>a[i+len]){
                ans++;
                book=1;
            }else if(a[i-len-1]==a[i+len]){
                if(book==1){
                    ans++;
                }
            }else{
                book=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}