#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    ll k;
    cin>>k;
    if(n<=50&&(1ll<<(n-1))<k){
        cout<<-1<<endl;
        return;
    }
    vector<int> ans(n+1);
    function<void(int,int,ll)> dfs=[&](int l,int r,ll now){
        for(int i=1;i<=n;i++){
            //cout<<ans[i]<<" ";
        }
        //cout<<endl;
        int len=r-l+1;
        int low=n-len+1;
        if(len==1){
            ans[l]=n;
            return;
        }
        if(len>=50){
            ans[l]=low;
            dfs(l+1,r,now);
        }else{
            if(now==1ll<<(len-1)){
                for(int i=l;i<=r;i++){
                    ans[i]=n-(i-l);
                }
                return;
            }
            int nnow=low;
            len--;
            while(len>=1&&now-(1ll<<(len-1))>0){
                now-=(1ll<<(len-1));
                len--;
                nnow++;
            }
            ans[l]=nnow;
            if(nnow==low){
                dfs(l+1,r,now);
                return;
            }
            int R=r+1;
            for(int i=r;i>=l;i--){
                ans[i]=low+r-i;
                if(ans[i]==nnow-1){
                    R=i;
                    break;
                }
            }
            dfs(l+1,R-1,now);
        }
    };
    dfs(1,n,k);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}