#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,mx;
int a[maxn],b[maxn];
ll lf[maxn],rg[maxn];
bool check(ll u,ll v,ll w,int h)
{
    ll sum=0;
    int l=upper_bound(lf+1,lf+n+1,u)-lf-1;
    int r=upper_bound(lf+1,lf+n+1,v)-lf-1;
    if(l==r){
        u-=rg[l-1],v-=rg[l-1];
        for(int i=u;i<=v;i++){
            if(b[l]==0){
                sum+=min(i,h);
            }else{
                sum+=min(a[l]-i+1,h);
            }
        }
    }else{
        u-=rg[l-1];
        //cout<<u<<" "<<a[l]<<endl;
        for(int i=u;i<=a[l];i++){
            if(b[l]==0){
                sum+=min(i,h);
            }else{
                sum+=min(a[l]-i+1,h);
            }
        }
        //cout<<sum<<endl;
        v-=rg[r-1];
        for(int i=1;i<=v;i++){
            if(b[r]==0){
                sum+=min(i,h);
            }else{
                sum+=min(a[r]-i+1,h);
            }
        }
        for(int i=l+1;i<r;i++){
            if(a[i]<=h)
                sum+=1ll*a[i]*(a[i]+1)/2;
            else sum+=1ll*h*(h-1)/2+(1ll*a[i]-h+1)*h;
        }
    }
    return sum>=w;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        lf[i]=rg[i-1]+1;
        rg[i]=lf[i]+a[i]-1;
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        int l=1,r=mx;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(u,v,w,mid))r=mid-1;
            else l=mid+1;
        }
        if(l==mx+1)cout<<-1<<endl;
        else cout<<l<<endl;
    }
    return 0;
}