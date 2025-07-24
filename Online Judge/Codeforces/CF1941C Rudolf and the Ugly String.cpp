#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,ans;
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>(s+1);
        if(n<=2){
            cout<<0<<endl;
            continue;
        }
        for(int i=2;i<=n-1;i++){
            if(s[i-1]=='m'&&s[i]=='a'&&s[i+1]=='p')
                ans++;
            if(s[i-1]=='p'&&s[i]=='i'&&s[i+1]=='e')
                ans++;
        }
        if(n<=4){
            cout<<ans<<endl;
            continue;
        }
        for(int i=3;i<=n-2;i++)
            if(s[i-2]=='m'&&s[i-1]=='a'&&s[i]=='p'&&s[i+1]=='i'&&s[i+2]=='e')
                ans--;
        cout<<ans<<endl;
    }
    return 0;
}