#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int cnt[maxn];
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>(s+1);
        n=strlen(s+1);
        s[n+1]='1';
        int lst=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                lst=i;
                break;
            }
        }
        if(lst==0){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            cnt[i]=cnt[i-1]+(s[i]=='1');
        ll ans=0;
        for(int i=lst;i<=n;i++){
            if(s[i]=='0'&&s[i+1]=='1'){
                int len=cnt[i];
                ans+=(1ll*len+1)*(i-lst+1-len);
                lst=i-len+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}