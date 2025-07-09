#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
//int dp[maxn][maxn][maxn*(maxn+1)];
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for (int i=1;i<=n;i++){//left
        cin>>a[i];
        a[i]--;
    }
    for (int i=1;i<=n;i++){//right
        cin>>b[i];
        b[i]--;
    }
    const int maxval=n*(n+1);
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(maxval,0x3f3f3f3f)));
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<maxval;k++){
                dp[i][j][k]=0x3f3f3f3f;
            }
        }
    }*/
    int val=0;
    for(int i=1;i<=n;i++)
        val+=(b[i]-a[i])*i;
    if(abs(val)>n*(n+1)||val<0){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<=n;i++)
        dp[i][0][val]=dp[0][i][val]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=max(0,val-i*(1+i));k<maxval;k++){
                dp[i][j][k]=min(dp[i-1][j][k],dp[i][j-1][k]);
                if(k+i+j<maxval&&!a[i]&&b[j]==1)
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][k+i+j]+1);
            }
        }
    }
    if(dp[n][n][0]==0x3f3f3f3f)
        cout<<-1<<endl;
    else
        cout<<dp[n][n][0]<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}