#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,x;
ll a[maxn],sum[maxn];
bool check(int num)
{
    for(int i=1;i+num<=n;i++){
        if(sum[i+num]-sum[i-1]<x*2){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>x;
    a[0]=sum[0]=a[n]=1e9;
    for(int i=1;i<n;i++){
        cin>>a[i];
        sum[i]=a[i]+sum[i-1];
    }
    sum[n]=sum[n-1]+a[n];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l+1;
    return 0;
}