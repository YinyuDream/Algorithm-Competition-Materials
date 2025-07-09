#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int maxm=1<<5;
void solve(){
    int n;
    cin>>n;
    string u,v;
    cin>>u>>v;
    u="."+u;
    v="."+v;
    vector<vector<array<int,2>>> dp(n+1,vector<array<int,2>>(maxm,{0,0}));
    vector<vector<array<int,2>>> from(n+1,vector<array<int,2>>(maxm,{-1,-1}));
    vector<array<char,7>> ans(n+1);
    dp[0][0][0]=dp[0][0][1]=1;
    auto check=[&](int pos,int j,int k,int op){
        j=j<<1;
        j|=u[pos]=='#';
        j|=(v[pos]=='#')<<6;
        k=k<<1;
        k|=u[pos-1]=='#';
        k|=(v[pos-1]=='#')<<6;
        vector<int> val(7);
        for(int i=0;i<7;i++){
            val[i]=((j>>i)&1)+((k>>i)&1);
        }
        if(op==1){
            for(int i=1;i<6;i++){
                if(val[i]==0){
                    bool find_1=false,find_2=false;
                    for(int j=i-1;j>=0;j--){
                        if(val[j]>=1){
                            find_1=true;
                            break;
                        }
                    }
                    for(int j=i+1;j<7;j++){
                        if(val[j]>=1){
                            find_2=true;
                            break;
                        }
                    }
                    if(find_1&&find_2){
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<7;i++){
            if(i<6&&val[i]==2&&val[i+1]==1){
                return false;
            }
            if(i>0&&val[i]==2&&val[i-1]==1){
                return false;
            }
        }
        return true;
    };
    for(int i=1;i<=n;i++){
        for(int j=0;j<maxm;j++){
            for(int k=0;k<maxm;k++){
                if(!dp[i-1][k][0]&&!dp[i-1][k][1]){
                    continue;
                }
                if(check(i,j,k,0)){
                    dp[i][j][0]=1;
                    from[i][j][0]=k;
                }
                if(check(i,j,k,1)){
                    dp[i][j][1]=1;
                    from[i][j][1]=k;
                }
            }
        }
    }
    bool find=false;
    for(int i=0;i<maxm;i++){
        if(dp[n][i][1]){
            find=true;
        }
    }
    cout<<dp[4][27][1]<<endl;
    if(!find){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}