#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,q;
int l[maxn],r[maxn],cnt;
unsigned long long shl[maxn],shr[maxn],pw[maxn];
char s[maxn];
ll query(int l,int r,int opt)
{
    if(opt==1){
        return shl[r]-shl[l-1]*pw[r-l+1];
    }else{
        return shr[l]-shr[r+1]*pw[r-l+1];
    }
}
ll work(int l,int r)
{
    int cnt[26],num;
    memset(cnt,0,sizeof(cnt));
    for(int i=l;i<=r;i++){
        cnt[s[i]-'a']++;
    }
    for(int i=0;i<=25;i++)
        if(cnt[i]>0)
            num++;
    if(num==1){
        return 0;
    }else if(num>=3){
        int mid=(r+l)/2;
        int q=0;
        int len=r-l+1;
        if((r+l)%2==0){
            q=(query(l,mid,1)==query(mid,r,2));
        }else{
            q=(query(l,mid,1)==query(mid+1,r,2));
        }
        return (1ll*len-1)*(len+2)/2-q*len;
    }else{
        int q=0;
        if((r-l+1)%2==0){
            
        }
    }
}
int main(){
    cin>>T;
    pw[0]=1;
    for(int i=1;i<maxn;i++)
        pw[i]=pw[i-1]*131;
    while(T--){
        cnt=0;
        cin>>n>>q;
        cin>>(s+1);
        for(int i=1;i<=n;i++)
            shl[i]=shl[i-1]*131+s[i]-'a';
        shr[n+1]=0;
        for(int i=n;i;i--)
            shr[i]=shr[i+1]*131+s[i]-'a';
        for(int i=1,l,r;i<=q;i++){
            cin>>l>>r;
            cout<<work(l,r)<<endl;
        }
    }  
    return 0;
}