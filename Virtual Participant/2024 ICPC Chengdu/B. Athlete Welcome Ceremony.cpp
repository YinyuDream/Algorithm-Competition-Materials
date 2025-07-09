#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=301;  
const ll mod=1e9+7;
int tot[maxn];
ll sum[maxn][maxn],ans[maxn][maxn],dp[maxn][maxn][maxn][3];
int main(){
    int n,Q;
    cin>>n>>Q;
    string s;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        tot[i]=tot[i-1]+(s[i]=='?');
    }
    if(s[1]=='?'){
        dp[1][1][0][0]=1;
        dp[1][0][1][1]=1;
        dp[1][0][0][2]=1;
    }else{
        dp[1][0][0][s[1]-'a']=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=tot[i];j++){
            for(int k=0;j+k<=tot[i];k++){
                if(s[i]=='?'){
                    if(j>0){
                        dp[i][j][k][0]=(dp[i-1][j-1][k][1]+dp[i-1][j-1][k][2])%mod;
                    }
                    if(k>0){
                        dp[i][j][k][1]=(dp[i-1][j][k-1][0]+dp[i-1][j][k-1][2])%mod;
                    }
                    dp[i][j][k][2]=(dp[i-1][j][k][0]+dp[i-1][j][k][1])%mod;
                }else{
                    dp[i][j][k][s[i]-'a']=(dp[i-1][j][k][0]+dp[i-1][j][k][1]+dp[i-1][j][k][2]-dp[i-1][j][k][s[i]-'a'])%mod;
                }
            }
        }
    }
    for(int i=0;i<=tot[n];i++){
        for(int j=0;i+j<=tot[n];j++){
            ans[i][j]=(dp[n][i][j][0]+dp[n][i][j][1]+dp[n][i][j][2])%mod;
        }
    }
    for(int i=0;i<=tot[n];i++){
        sum[i][0]=ans[i][0];
        for(int j=1;j<=tot[n];j++){
            sum[i][j]=sum[i][j-1]+ans[i][j];
        }
    }
    while(Q--){
        int x,y,z;
        cin>>x>>y>>z;
        ll val=0;
        for(int i=0;i<=min(x,tot[n]);i++){
            int l=tot[n]-i-min(z,tot[n]),r=tot[n]-i;
            l=max(l,0),r=min(r,min(y,tot[n]));
            if(l>r) continue;
            val+=sum[i][r]-sum[i][l]+ans[i][l];
            val%=mod;
        }
        cout<<(val+mod)%mod<<endl;
    }
    return 0;
}