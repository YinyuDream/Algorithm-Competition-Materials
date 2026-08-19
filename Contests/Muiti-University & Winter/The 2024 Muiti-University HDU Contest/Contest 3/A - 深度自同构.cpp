#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int p=998244353;
int tot,top;
int f[maxn],prime[maxn],not_prime[maxn];
pair<int,int> stk[maxn];
void init(){
    for(int i=2;i<maxn;i++){
        if(!not_prime[i]) prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
void write(int x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
void solve(){
    int n,cnt=0;
    cin>>n;
    f[0]=f[1]=1;
    cout<<1<<' ';
    function <void(int,int,int&)> dfs=[&](int pos,int val,int& ans){
        if(pos==top+1){
            ans+=f[val-1];
            if(ans>=p) ans-=p;
            return;
        }
        int res=1;
        for(int i=0;i<=stk[pos].second;i++){
            dfs(pos+1,val*res,ans);
            res*=stk[pos].first;
        }
    };
    for(int i=2;i<=n;i++){
        top=0;
        int lim=sqrt(i),val=i;
        for(int j=1;j<=tot&&prime[j]<=lim;j++){
            if(val%prime[j]==0){
                int cnt=0;
                while(val%prime[j]==0){
                    val/=prime[j];
                    cnt++;
                }
                stk[++top]={prime[j],cnt};
            }
        }
        if(val>1) stk[++top]={val,1};
        dfs(1,1,f[i]);
        write(f[i]),putchar(' ');
    }
}
int main(){
    init();
    solve();
    return 0;
}