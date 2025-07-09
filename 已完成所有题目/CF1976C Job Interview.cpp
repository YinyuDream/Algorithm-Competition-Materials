#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
int a[maxn],b[maxn],sum_a[maxn],sum_b[maxn];
ll tot_a[maxn],tot_b[maxn],suffix_a[maxn],suffix_b[maxn];
bool check(int pos,int mid)
{
    if(mid<pos){
        return sum_a[mid]<=n&&sum_b[mid]<=m;
    }else{
        return sum_a[mid+1]-(a[pos]>b[pos])<=n&&(sum_b[mid+1]-(b[pos]>a[pos])<=m);
    }
}
ll work(int pos)
{
    int l=1,r=n+m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(pos,mid))l=mid+1;
        else r=mid-1;
    }
    int mx=r;
    if(mx<pos){
        if(sum_a[mx]==n){
            return tot_a[mx]+tot_b[mx]+suffix_b[mx+1]-b[pos];
        }else{
            return tot_a[mx]+tot_b[mx]+suffix_a[mx+1]-a[pos];
        }
    }else{
        if(sum_a[mx+1]-(a[pos]>b[pos])==n){
            return tot_a[mx+1]+tot_b[mx+1]-max(a[pos],b[pos])+suffix_b[mx+2];
        }else{
            return tot_a[mx+1]+tot_b[mx+1]-max(a[pos],b[pos])+suffix_a[mx+2];
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n+m+1;i++)
            cin>>a[i];
        for(int i=1;i<=n+m+1;i++)
            cin>>b[i];
        for(int i=1;i<=n+m+1;i++)
            sum_a[i]=sum_a[i-1]+(a[i]>b[i]);
        for(int i=1;i<=n+m+1;i++)
            sum_b[i]=sum_b[i-1]+(b[i]>a[i]);
        for(int i=1;i<=n+m+1;i++)
            tot_a[i]=tot_a[i-1]+a[i]*(a[i]>b[i]);
        for(int i=1;i<=n+m+1;i++)
            tot_b[i]=tot_b[i-1]+b[i]*(b[i]>a[i]);
        suffix_a[n+m+2]=suffix_b[n+m+2]=0;
        for(int i=n+m+1;i>=1;i--)
            suffix_a[i]=suffix_a[i+1]+a[i];
        for(int i=n+m+1;i>=1;i--)
            suffix_b[i]=suffix_b[i+1]+b[i];
        for(int i=1;i<=n+m+1;i++)
            cout<<work(i)<<' ';
        cout<<endl;
    }
    return 0;
}