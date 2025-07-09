#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
void solve(){
    int n,k;
    n=read(),k=read();
    vector<vector<int>> a(n+1,vector<int>(5));
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,1e18));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            a[i][j]=read();
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int k=0;k<=min(j,4);k++)
                if(j>=k)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-k]+a[i][k]);
    write(dp[n][k]),putchar('\n');
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}