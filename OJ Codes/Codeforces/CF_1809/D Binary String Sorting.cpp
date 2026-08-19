#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll val=1e12;
int T,n;
int sum_0[maxn],sum_1[maxn];
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>(s+1);
        n=strlen(s+1);
        for(int i=0;i<=n+1;i++)
            sum_0[i]=sum_1[i]=0;
        for(int i=1;i<=n;i++)
            sum_1[i]=sum_1[i-1]+(s[i]=='1');
        for(int i=n;i>=1;i--)
            sum_0[i]=sum_0[i+1]+(s[i]=='0');
        ll ans=1e18;
        for(int i=1;i<n;i++){
            ans=min(ans,(val+1)*sum_1[i]+(val+1)*sum_0[i+1]);
            if(s[i]=='1'&&s[i+1]=='0')
                ans=min(ans,(val+1)*(sum_1[i-1]+sum_0[i+2])+val);
        }
        ans=min(ans,(val+1)*sum_1[n]);
        ans=min(ans,(val+1)*sum_0[1]);
        cout<<ans<<endl;
    }
    return 0;
}