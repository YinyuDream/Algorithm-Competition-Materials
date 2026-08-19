#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int p1=131,p2=133,mod1=1e9+7,mod2=1e9+9;
int T,n,low,up;
string s;
int hash1[maxn],hash2[maxn],pw1[maxn],pw2[maxn];
void init(){
    hash1[0]=hash2[0]=0;
    for(int i=1;i<=n;i++){
        hash1[i]=(1ll*hash1[i-1]*p1+s[i-1])%mod1;
        hash2[i]=(1ll*hash2[i-1]*p2+s[i-1])%mod2;
    }
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=n;i++){
        pw1[i]=1ll*pw1[i-1]*p1%mod1;
        pw2[i]=1ll*pw2[i-1]*p2%mod2;
    }
}
int gethash(int l,int r,int *hash,int mod,int p){
    return (hash[r]-1ll*hash[l-1]*p%mod+mod)%mod;
}
bool check(int len)
{
    int h1=gethash(1,len,hash1,mod1,pw1[len]);
    int h2=gethash(1,len,hash2,mod2,pw2[len]);
    int cnt=1,now=len+1;
    while(now<=n){
        if(now+len-1>n)break;
        int t1=gethash(now,now+len-1,hash1,mod1,pw1[len]);
        int t2=gethash(now,now+len-1,hash2,mod2,pw2[len]);
        if(t1==h1&&t2==h2){
            cnt++;
            now+=len;
        }
        else now++;
    }
    if(cnt>=low)
        return true;
    else
        return false;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>low>>up>>s;
        init();
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        cout<<r<<endl;
    }
    return 0;
}