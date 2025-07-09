#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    const int maxlen=5;
    int n,ans=0;
    cin>>n;
    vector<int>a(n+2,0);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<int>pos;
    pos.push_back(0);
    for(int i=1;i<=n;i++){
        if(a[i]>maxlen){
            ans++;
            pos.push_back(i);
            a[i]=0;
        }
    }
    pos.push_back(n+1);
    set<int>st;
    auto check=[&](int x){
        for(int i=1;i<maxlen;i++){
            if((x&(1<<(i-1)))&&(x&(1<<i)))
                return false;
        }
        return true;
    };
    for(int i=0;i<(1<<maxlen);i++){
        if(check(i)){
            st.insert(i);
        }
    }
    auto count=[&](int x){
        int cnt=0;
        for(int i=0;i<maxlen;i++)
            if(x&(1<<i))
                cnt++;
        return cnt;
    };
    for(auto i=1;i<pos.size();i++){
        int l=pos[i-1]+1,r=pos[i];
        if(l>r)
            continue;
        if(l==r){
            continue;
        }
        if(l+1==r){
            ans+=min(a[l],1);
            continue;
        }
        vector<vector<int>> f(n+2,vector<int>(1<<maxlen,0x3f3f3f3f));
        f[l+1][(1<<a[l+1])-1]=1;
        for(auto x:st){
            int val=x|(x<<1),cnt=count(x);
            if(((~val)&((1<<a[l])-1))==0){
                f[l+1][(~val)&((1<<a[l+1])-1)]=min(f[l+1][(~val)&((1<<a[l+1])-1)],cnt);
            }
        }
        for(int i=l+1;i<r;i++){
            for(int j=0;j<(1<<maxlen);j++){
                f[i+1][(1<<a[i+1])-1]=min(f[i+1][(1<<a[i+1])-1],f[i][j]+1);
            }
            for(int j=0;j<(1<<maxlen);j++){
                for(auto x:st){
                    int val=x|(x<<1),cnt=count(x);
                    if(((~val)&j)==0){
                        f[i+1][(~val)&((1<<a[i+1])-1)]=min(f[i+1][(~val)&((1<<a[i+1])-1)],f[i][j]+cnt);
                    }
                }
            }
        }
        ans+=f[r][0];
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}