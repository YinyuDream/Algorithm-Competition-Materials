#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll qpow(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll ans=qpow(a,b/2);
    ans=ans*ans%mod;
    if(b&1)ans=ans*a%mod;
    return ans;
}
const ll inv2=qpow(2,mod-2);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<vector<int>> nums(n+1);
    for(int i=1;i<=n;i++){
        while(a[i]){
            nums[i].push_back(a[i]%k);
            a[i]/=k;
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        if(mx<nums[i].size()){
            mx=nums[i].size();
        }
    }
    for(int i=1;i<=n;i++){
        nums[i].resize(mx,0);
    }
    vector<ll> pwk(mx);
    pwk[0]=1;
    for(int i=1;i<mx;i++)
        pwk[i]=pwk[i-1]*k%mod;
    vector<vector<ll>> cnt(mx,vector<ll>(k));//cnt[i][j]:j*k^i
    for(int i=1;i<=n;i++){
        for(int j=0;j<mx;j++){
            cnt[j][nums[i][j]]++;
        }
    }
    ll ans=0;
    for(int i=0;i<mx;i++){
        for(int j=0;j<k;j++){
            ans=(ans+pwk[i]*cnt[i][j]%mod*(cnt[i][j]-1)%mod*inv2%mod*((j+j)%k)%mod)%mod;
            for(int l=j+1;l<k;l++){
                ans=(ans+pwk[i]*cnt[i][j]%mod*cnt[i][l]%mod*((j+l)%k))%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}