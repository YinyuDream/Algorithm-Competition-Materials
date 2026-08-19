#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T,n,m,k;
int a[maxn],b[maxn],c[maxn];
int num(int posa,int posb,int posc)
{
    return abs(b[posb]+c[posc]-a[posa]);
}
int find(int posa,int posb,int l,int r)
{
    int avg=(1ll*a[posa]+a[posa+1])/2;
    int posc_l=upper_bound(c+l,c+r+1,avg-b[posb])-c-1;
    int posc_r=upper_bound(c+l,c+r+1,avg-b[posb])-c;
    int ans=2e9;
    if(b[posb]+c[l]<=avg)ans=min(ans,max(num(posa,posb,posc_l),num(posa+1,posb,posc_l)));
    if(b[posb]+c[r]>avg)ans=min(ans,max(num(posa,posb,posc_r),num(posa+1,posb,posc_r)));
    return ans;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        for(int i=1;i<=k;i++)
            cin>>c[i];
        sort(b+1,b+m+1);
        sort(c+1,c+k+1);
        int mx=0,pos=0,flag=1;
        for(int i=2;i<=n;i++){
            if(mx<a[i]-a[i-1]){
                mx=a[i]-a[i-1];
                pos=i-1;
                flag=1;
            }else if(mx==a[i]-a[i-1]){
                flag=0;
            }
        }
        if(flag==0){
            cout<<mx<<endl;
            continue;
        }
        int ans=mx;
        for(int i=1;i<=m;i++){
            if(b[i]>=a[pos+1])
                break;
            else if(b[i]>=a[pos]){
                if(b[i]+c[1]>=a[pos+1]){
                    break;
                }
                int p=lower_bound(c+1,c+k+1,a[pos+1]-b[i])-c;
                ans=min(ans,find(pos,i,1,p-1));
            }else{
                if(b[i]+c[k]<=a[pos])
                    continue;
                if(b[i]+c[1]>=a[pos+1])
                    break;
                int l=upper_bound(c+1,c+k+1,a[pos]-b[i])-c;
                int r=lower_bound(c+1,c+k+1,a[pos+1]-b[i])-c-1;
                if(l<=r) ans=min(ans,find(pos,i,l,r));
            }
        }
        for(int i=1;i<n;i++)
            if(i!=pos)
                ans=max(ans,a[i+1]-a[i]);
        cout<<ans<<endl;
    }
    return 0;
}