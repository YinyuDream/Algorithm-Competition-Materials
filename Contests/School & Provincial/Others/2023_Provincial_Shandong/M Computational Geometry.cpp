#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
ll x[maxn],y[maxn];
ll S(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        for(int i=n+1;i<=n*2;i++)
            x[i]=x[i-n],y[i]=y[i-n];
        ll ans=0,area=0;
        int pos=k+2;
        for(int i=2;i<=k;i++)
            area+=S(x[1],y[1],x[i],y[i],x[i+1],y[i+1]);
        while(pos+1<=n&&S(x[1],y[1],x[k+1],y[k+1],x[pos],y[pos])<=S(x[1],y[1],x[k+1],y[k+1],x[pos+1],y[pos+1]))
            pos++;
        ans=max(ans,area+S(x[1],y[1],x[k+1],y[k+1],x[pos],y[pos]));
        for(int i=2;i<=n;i++){
            area-=S(x[i-1],y[i-1],x[i],y[i],x[i+k-1],y[i+k-1]);
            area+=S(x[i],y[i],x[i+k-1],y[i+k-1],x[i+k],y[i+k]);
            while(pos+1<=n+i-1&&S(x[i],y[i],x[i+k],y[i+k],x[pos],y[pos])<=S(x[i],y[i],x[i+k],y[i+k],x[pos+1],y[pos+1]))
                pos++;
            ans=max(ans,area+S(x[i],y[i],x[i+k],y[i+k],x[pos],y[pos]));
        }
        cout<<fixed<<setprecision(12)<<1.0*ans/2<<endl;
    }
    return 0;
}