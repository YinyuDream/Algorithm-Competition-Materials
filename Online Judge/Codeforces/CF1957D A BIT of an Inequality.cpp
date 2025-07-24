#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int T,n;
int a[maxn],sum[maxn],cnt[maxn][30];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]^a[i];
            for(int j=0;j<30;j++)
                cnt[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                cnt[i][j]=cnt[i-1][j]+((sum[i]>>j)&1);
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            int num=a[i],pos=0;
            while(num){
                num>>=1;
                pos++;
            }
            pos--;
            ans+=1ll*cnt[i-1][pos]*(cnt[n][pos]-cnt[i-1][pos]);
            ans+=(1ll*i-cnt[i-1][pos])*(n-i+1-cnt[n][pos]+cnt[i-1][pos]);
        }
        cout<<ans<<endl;
    }
    return 0;
}