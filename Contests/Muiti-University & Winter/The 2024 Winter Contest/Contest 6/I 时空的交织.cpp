#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
ll ans,a[maxn],b[maxn];
ll suma[maxn],sumb[maxn],minx,maxx,mxa,mna,mxb,mnb;
template<typename T>
T myMax(T a) {
    return a;
}
template<typename T, typename... Args>
T myMax(T first, Args... args) {
    T rest = myMax(args...);
    return first > rest ? first : rest;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        suma[i]=suma[i-1]+a[i];
    for(int i=1;i<=m;i++)
        sumb[i]=sumb[i-1]+b[i];
    minx=maxx=0;
    mxa=-1e18,mna=1e18;
    for(int i=1;i<=n;i++){
        mxa=max(mxa,suma[i]-minx);
        mna=min(mna,suma[i]-maxx);
        minx=min(minx,suma[i]);
        maxx=max(maxx,suma[i]);
    }
    minx=maxx=0;
    mxb=-1e18,mnb=1e18;
    for(int i=1;i<=m;i++){
        mxb=max(mxb,sumb[i]-minx);
        mnb=min(mnb,sumb[i]-maxx);
        minx=min(minx,sumb[i]);
        maxx=max(maxx,sumb[i]);
    }
    ans=myMax(mxa*mxb,mxa*mnb,mna*mxb,mna*mnb);
    cout<<ans;
    return 0;
}