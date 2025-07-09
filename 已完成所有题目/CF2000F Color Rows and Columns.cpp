#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,mx=0;
    cin>>n>>k;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(a[i]<b[i])
            swap(a[i],b[i]);
        mx=max(mx,a[i]);
    }
    vector<vector<int>> val(n+1,vector<int>(max(2*mx+1,k+1),-1));
    for(int i=1;i<=n;i++){
        int _a=a[i],_b=b[i],_tot=0;
        for(int j=0;j<a[i]+b[i];j++){
            val[i][j]=_tot;
            if(_a<=_b){
                _tot+=_a;
                _b--;
            }else{
                _tot+=_b;
                _a--;
            }
        }
        val[i][a[i]+b[i]]=val[i][a[i]+b[i]-1];
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,0x3f3f3f3f));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int l=0;l<=j;l++){
                if(val[i][j-l]==-1||dp[i-1][l]==0x3f3f3f3f)
                    continue;
                dp[i][j]=min(dp[i][j],dp[i-1][l]+val[i][j-l]);
            }
        }
    }
    if(dp[n][k]==0x3f3f3f3f)
        cout<<-1<<endl;
    else
        cout<<dp[n][k]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}