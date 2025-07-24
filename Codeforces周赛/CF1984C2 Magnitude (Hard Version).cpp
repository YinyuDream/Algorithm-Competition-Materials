#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int mod=998244353;
int T,n;
ll a[maxn],f[maxn],g[maxn],sum[maxn],cnt[maxn];
struct Cmp1 {
    bool operator()(int x, int y) const {
        return f[x] - sum[x] > f[y] - sum[y];
    }
};

struct Cmp2 {
    bool operator()(int x, int y) const {
        return f[x] - sum[x] < f[y] - sum[y];
    }
};
int main(){
    cin>>T;
    while(T--){
        priority_queue<int, vector<int>, Cmp1> p;
        priority_queue<int, vector<int>, Cmp2> q;
        map<ll,ll> mp;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
            cnt[i]=f[i];
            g[i]=1e18;
        }
        g[0]=0;
        mp.insert(make_pair(0,1));
        q.push(0);
        p.push(0);
        cnt[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)
                if(abs(f[j]+sum[i]-sum[j])>f[i]){
                    f[i]=abs(f[j]+sum[i]-sum[j]);
                }else if(abs(f[j]+sum[i]-sum[j])==f[i]){
                    cnt[i]+=cnt[j];
                }
                
            /*ll val_1=-1,val_2=-1;
            f[i]=max(abs(f[q.top()]+sum[i]-sum[q.top()]),abs(f[p.top()]+sum[i]-sum[p.top()]));
            if(abs(f[q.top()]+sum[i]-sum[q.top()])==f[i])
                val_1=f[q.top()]-sum[q.top()];
            if(abs(f[p.top()]+sum[i]-sum[p.top()])==f[i])
                val_2=f[p.top()]-sum[p.top()];
            if(val_1==-1||val_2==-1){
                cnt[i]=max(mp[val_1],mp[val_2]);
            }else{
                if(val_1==val_2){
                    cnt[i]=mp[val_1];
                }else{
                    cnt[i]=mp[val_1]+mp[val_2];
                    cnt[i]%=mod;
                }
            }
            if(mp.find(f[i]-sum[i])==mp.end()){
                mp.insert(make_pair(f[i]-sum[i],cnt[i]));
            }else{
                mp[f[i]-sum[i]]+=cnt[i];
                mp[f[i]-sum[i]]%=mod;
            }*/
            p.push(i);
            q.push(i);
        }
        ll tot=0;
        for(int i=0;i<=n;i++){
            if(f[i]+sum[n]-sum[i]==f[n]){
                tot+=cnt[i];
                tot%=mod;
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}