#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
int T,n,mx,ans;
int can[maxn];
char s[maxn];
bool check(int len){
    if(len==0)
        return true;
    for(int i=1;i<=n;i++)
        can[i]=0;
    for(int i=1;i+len<=n;i++){
        if(s[i]==s[i+len]||s[i]=='?'||s[i+len]=='?')
            can[i]=1;
        else
            can[i]=0;
    }
    for(int i=1;i+len-1<=n;i++)
        can[i]+=can[i-1];
    for(int i=1;i<=n-len*2+1;i++)
        if(can[i+len-1]-can[i-1]==len)
            return true;
    return false;
}
int main(){
    cin>>T;
    while(T--){
        cin>>(s+1);
        n=strlen(s+1);
        mx=n/2;
        for(int i=mx;i>=0;i--){
            if(check(i)){
                ans=i;
                break;
            }
        }
        cout<<ans*2<<endl;
    }
    return 0;
}