#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k,q;
    //cin>>n>>k>>q;
    n=2e5,k=1e5,q=2e5;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        //cin>>a[i];
        if(i<=1e5)a[i]=1;
        else a[i]=i-1e5+1;
        a[i]-=i;
    }
    map<int,int>cnt;
    multiset<int> st;
    for(int i=1;i<=k;i++)
        cnt[a[i]]++;
    for(auto [x,y]:cnt){
        st.insert(y);
    }
    for(int i=k+1;i<=n;i++)
        if(cnt.find(a[i])==cnt.end())
            cnt.insert({a[i],0});
    vector<int> ans(n-k+2);
    ans[1]=k-*st.rbegin();
    for(int i=2;i+k-1<=n;i++){
        st.erase(st.find(cnt[a[i-1]]));
        cnt[a[i-1]]--;
        if(cnt[a[i-1]]>0)
            st.insert(cnt[a[i-1]]);
        if(cnt[a[i+k-1]]!=0)
            st.erase(st.find(cnt[a[i+k-1]]));
        cnt[a[i+k-1]]++;
        st.insert(cnt[a[i+k-1]]);
        ans[i]=k-*st.rbegin();
    }
    vector<vector<int>> dp(n-k+2,vector<int>(19,0x3f3f3f3f));
    for(int i=1;i<=n-k+1;i++)
        dp[i][0]=ans[i];
    for(int j=1;j<19;j++)
        for(int i=1;i+(1<<j)-1<=n-k+1;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    auto query=[&](int l,int r){
        int k=31-__builtin_clz(r-l+1);
        return min(dp[l][k],dp[r-(1<<k)+1][k]);
    };
    while(q--){
        if(q%100==0){
            cout<<q<<endl;
        }
        int u,v;
        //cin>>u>>v;
        u=1,v=n;
        v=v-k+1;
        ll tot=0;
        int now=u;
        while(now<=v){
            int l=now,r=v,val=ans[now];
            while(l<=r){
                int mid=(l+r)/2;
                if(query(now,mid)<val){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            tot+=(1ll*r-now+1)*val;
            now=r+1;
        }
        //cout<<tot<<'\n';
    }
}
int main(){
    int T;
    //cin>>T;
    T=1;
    while(T--){
        solve();
    }
    return 0;
}