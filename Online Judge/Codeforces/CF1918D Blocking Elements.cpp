#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll a[maxn],sum[maxn],f[maxn];
ll S(int l,int r){
    if(l>r)return 0;
    return sum[r]-sum[l-1];
}
bool check(ll x){
    deque<int>q;
    q.push_back(0);
    for(int i=1;i<=n;i++)
        f[i]=1e18;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&S(q.front()+1,i-1)>x)q.pop_front();
        f[i]=f[q.front()]+a[i];
        while(!q.empty()&&f[q.back()]>f[i])q.pop_back();
        q.push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(S(i+1,n)<=x&&f[i]<=x){
            return true;
        }
    }
    return false;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        ll l=0,r=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            r+=a[i];
            sum[i]=sum[i-1]+a[i];
        }
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}