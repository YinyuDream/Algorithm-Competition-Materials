#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    ll num,val;
};
bool operator < (node a,node b){
    return a.val<b.val;
}
void solve(){
    int n;
    ll m;
    cin>>n>>m;
    vector<node> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i].val;
    for(int i=0;i<n;i++)
        cin>>a[i].num;
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,min(m/a[i].val,a[i].num)*a[i].val);
    for(int i=0;i<n-1;i++){
        if(a[i+1].val!=a[i].val+1)
            continue;
        if(a[i].val*a[i].num<=m){
            ll t=m-a[i].val*a[i].num;
            ll num=min(a[i+1].num,t/a[i+1].val);
            if(num==a[i+1].num)
                ans=max(ans,a[i].val*a[i].num+a[i+1].val*num);
            else{
                ll val=min(a[i].num,a[i+1].num-num);
                ll now=a[i].val*a[i].num+a[i+1].val*num;
                val=min(val,m-now);
                ans=max(ans,now+val);
            }
        }else{
            ll num=m/a[i].val;
            ll val=min(min(num,a[i+1].num),m-num*a[i].val);
            ans=max(ans,a[i].val*num+val);
        }
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