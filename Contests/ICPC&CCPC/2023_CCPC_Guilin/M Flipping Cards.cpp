#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,l=1e9,r;
int a[maxn],b[maxn],f[maxn][3];
bool check(int val)
{
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++){
        f[i][0]=f[i-1][0]+(a[i]>=val);
        f[i][1]=max(f[i-1][0],f[i-1][1])+(b[i]>=val);
        f[i][2]=max(f[i-1][1],f[i-1][2])+(a[i]>=val);
    }
    return max(f[n][0],max(f[n][1],f[n][2]))>=(n+1)/2;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        l=min(l,min(a[i],b[i]));
        r=max(r,max(a[i],b[i]));
    }
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}