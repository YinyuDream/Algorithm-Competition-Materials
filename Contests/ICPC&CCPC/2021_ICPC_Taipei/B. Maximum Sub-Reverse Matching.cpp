#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,origin=0;
    string s,t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
        if(s[i]==t[i])origin++;
    }
    int ans=origin,l=0,r=0;
    for(int i=0;i<n;i++){
        string u=t;
        int now=origin;
        for(int len=1;i-len+1>=0 && i+len-1<n;len++){
            int cur=(u[i-len+1]==s[i-len+1])+(u[i+len-1]==s[i+len-1]);
            swap(u[i-len+1],u[i+len-1]);
            now-=cur;
            now+=(u[i-len+1]==s[i-len+1])+(u[i+len-1]==s[i+len-1]);
            if(now>ans){
                ans=now;
                l=i-len+1;
                r=i+len-1;
            }else if(now==ans){
                if((i+len-1)-(i-len+1)<(r-l)){
                    l=i-len+1;
                    r=i+len-1;
                }else if((i+len-1)-(i-len+1)==(r-l)&&(i-len+1)<l){
                    l=i-len+1;
                    r=i+len-1;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        string u=t;
        int now=origin;
        for(int len=1;i-len+1>=0 && i+len<n;len++){
            int cur=(u[i-len+1]==s[i-len+1])+(u[i+len]==s[i+len]);
            swap(u[i-len+1],u[i+len]);
            now-=cur;
            now+=(u[i-len+1]==s[i-len+1])+(u[i+len]==s[i+len]);
            if(now>ans){
                ans=now;
                l=i-len+1;
                r=i+len;
            }else if(now==ans){
                if((i+len)-(i-len+1)<(r-l)){
                    l=i-len+1;
                    r=i+len;
                }else if((i+len)-(i-len+1)==(r-l)&&(i-len+1)<l){
                    l=i-len+1;
                    r=i+len;
                }
            }
        }
    }
    cout<<origin<<" "<<ans<<" ";
    cout<<l+1<<" "<<r+1<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}