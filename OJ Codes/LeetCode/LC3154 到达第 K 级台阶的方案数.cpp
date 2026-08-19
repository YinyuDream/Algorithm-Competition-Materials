class Solution {
public:
    int waysToReachStair(int k) {
        typedef long long ll;
        ll _k=k;
        vector<ll> pw2(31);
        pw2[0]=1;
        for(int i=1;i<=30;i++){
            pw2[i]=pw2[i-1]*2;
        }
        for(int i=1;i<=30;i++){
            pw2[i]+=pw2[i-1];
        }
        ll ans=(_k<=1);
        vector<vector<ll>> C(33,vector<ll>(33,0));
        C[0][0]=1;
        for(int i=1;i<=32;i++){
            C[i][0]=1;
            for(int j=1;j<=i;j++){
                C[i][j]=C[i-1][j-1]+C[i-1][j];
            }
        }
        for(int i=1;i<=31;i++){
            if(1+pw2[i-1]<_k){
                continue;
            }
            ll delta=1+pw2[i-1]-_k;
            if(delta>i+1){
                continue;
            }
            ans+=C[i+1][(int)delta];
        }
        return ans;
    }
};