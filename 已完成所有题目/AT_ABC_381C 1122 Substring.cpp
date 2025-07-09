#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s+" ";
    vector<int> f(n+2,0),g(n+2,0);
    for(int i=1;i<=n;i++){
        if(s[i]!='1'){
            f[i]=0;
        }else{
            f[i]=f[i-1]+1;
        }
    }
    for(int i=n;i>=1;i--){
        if(s[i]!='2'){
            g[i]=0;
        }else{
            g[i]=g[i+1]+1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='/'){
            ans=max(ans,2*min(f[i-1],g[i+1])+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}