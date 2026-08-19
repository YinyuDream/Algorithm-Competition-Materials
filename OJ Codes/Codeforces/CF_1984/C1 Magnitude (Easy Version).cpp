#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const ll inf=1e18;
int T,n;
ll a[maxn],f[maxn],sum[maxn];
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
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        f[1]=abs(a[1]);
        p.push(1);
        q.push(1);
        for(int i=2;i<=n;i++){
            f[i]=abs(sum[i]);
            f[i]=max(f[i],abs(f[q.top()]+sum[i]-sum[q.top()]));
            f[i]=max(f[i],abs(f[p.top()]+sum[i]-sum[p.top()]));
            p.push(i);
            q.push(i);
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,f[i]+sum[n]-sum[i]);
        cout<<f[n]<<endl;
    }
    return 0;
}