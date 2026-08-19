#include<bits/stdc++.h>
using namespace std;
const int N=501;
int mx[N],dp[N][N][512],sum[N][N][512];
void init()
{
    mx[0]=0;
    for(int i=1;i<N;i++){
        if(__builtin_popcount(i)==1){
            mx[i]=i<<1;
        }else{
            mx[i]=mx[i-1];
        }
    }
}
void solve()
{
    int n,p,m;
    cin>>n>>p>>m;
    dp[0][0][0]=sum[0][0][0]=1;
    for(int i=1;i<=n-p;i++){
        for(int k=0;k<mx[i];k++){
            for(int j=1;j<=i;j++){
                dp[i][j][k]+=sum[i-j][min(i-j,j)][k^j];
                dp[i][j][k]%=m;
            }
            sum[i][0][k]=dp[i][0][k];
            for(int j=1;j<=i;j++){
                sum[i][j][k]=(sum[i][j-1][k]+dp[i][j][k])%m;
            }
        }
    }
    cout<<sum[n-p][n-p][p]<<endl;
}
int main(){
    init();
    solve();
}