#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans,cnt[maxn];
char s[maxn];
int main(){
    cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        cnt[i]=cnt[i-1]+(s[i]=='1');
    ans=cnt[n];
    for(int mid=1;mid<=n;mid++){
        for(int len=1;mid-len+1>=1&&mid+len-1<=n;len++){
            if(len==1&&s[mid]=='1'){
                break;
            }
            if(s[mid-len+1]!=s[mid+len-1])
                break;
            ans=min(ans,cnt[n]-cnt[mid+len-1]+cnt[mid-len]+(cnt[mid+len-1]-cnt[mid-len])/2);
        }
    }
    for(int mid=1;mid<n;mid++){
        for(int len=1;mid-len+1>=1&&mid+len<=n;len++){
            if(s[mid-len+1]!=s[mid+len])
                break;
            ans=min(ans,cnt[n]-cnt[mid+len]+cnt[mid-len]+(cnt[mid+len]-cnt[mid-len])/2);
        }
    }
    cout<<ans<<endl;
    return 0;
}