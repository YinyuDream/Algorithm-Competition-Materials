#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn],gcd[maxn][20];
bool check(int len)
{
    for(int i=1;i+len-1<=n;i++){
        int k=log2(len);
        if(__gcd(gcd[i][k],gcd[i+len-(1<<k)][k])==1)return true;
    }
    return false;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        gcd[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            gcd[i][j]=__gcd(gcd[i][j-1],gcd[i+(1<<(j-1))][j-1]);
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    if(l==n+1) cout<<-1;
    else cout<<l-1+n-1<<endl;
    return 0;
}