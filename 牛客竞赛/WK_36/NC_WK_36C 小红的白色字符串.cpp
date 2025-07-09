#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,top,cnt,ans;
char s[maxn];
int t[maxn],l[maxn],r[maxn];
int main(){
    cin>>(s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(!top){
            if(s[i]>='a'&&s[i]<='z'){
                t[++top]=0;
            }else{
                t[++top]=1;
            }
        }else if(s[i]>='a'&&s[i]<='z'){
            if(t[top]==1){
                t[++top]=0;
            }
        }else{
            t[++top]=1;
        }
    }
    for(int i=0;i<=top;i++){
        if(t[i]==0&&t[i+1]==1){
            l[++cnt]=i+1;
        }
        if(t[i]==1&&t[i+1]==0){
            r[cnt]=i;
        }
    }
    if(cnt==0){
        cout<<0;
        return 0;
    }
    if(l[1]==1){
        ans=(r[1]-l[1]+1)/2;
    }else{
        ans=(r[1]-l[1])/2+1;
    }
    for(int i=2;i<=cnt;i++)
        ans+=(r[i]-l[i])/2+1;
    cout<<ans;
    return 0;
}