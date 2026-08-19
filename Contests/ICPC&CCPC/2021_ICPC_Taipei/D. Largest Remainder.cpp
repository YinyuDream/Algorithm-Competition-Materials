#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=16,maxk=200;
int a[maxd],pw10[maxd];
int dp[1<<maxd][maxk],fr_val[1<<maxd][maxk],fr_mod[1<<maxd][maxk];
int main(){
    int d,k;
    cin>>d>>k;
    pw10[0]=1;
    for(int i=0;i<d;i++)
        cin>>a[i];
    for(int i=1;i<d;i++)
        pw10[i]=pw10[i-1]*10%k;
    sort(a,a+d);
    vector<int> s[d+1];
    for(int i=0;i<(1<<d);i++)
        s[__builtin_popcount(i)].push_back(i);
    for(int i=0;i<d;i++)
        dp[1<<i][a[0]*pw10[i]%k]=1;
    fr_val[0][0]=fr_mod[0][0]=-1;
    for(int i=1;i<d;i++){
        for(auto j:s[i+1]){
            for(int l=0;l<k;l++){
                for(int m=0;m<d;m++){
                    if((j&(1<<m))){
                        int val=(l-a[i]*pw10[m])%k;
                        if(val<0)val+=k;
                        if(dp[j^(1<<m)][val]){
                            dp[j][l]=1;
                            fr_val[j][l]=j^(1<<m);
                            fr_mod[j][l]=val;
                        }
                    }
                }
            }
        }
    }
    vector<int> res,ans(d);
    for(int i=k-1;i>=0;i--){
        if(dp[(1<<d)-1][i]){
            int cur_val=(1<<d)-1,cur_mod=i;
            while(fr_val[cur_val][cur_mod]!=-1){
                int pos=__builtin_ctz(fr_val[cur_val][cur_mod]^cur_val);
                res.push_back(pos);
                int tmp=cur_val;
                cur_val=fr_val[tmp][cur_mod];
                cur_mod=fr_mod[tmp][cur_mod];
            }
            break;
        }
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<d;i++)
        ans[d-res[i]-1]=a[i];
    for(auto i:ans)
        cout<<i;
    return 0;
}