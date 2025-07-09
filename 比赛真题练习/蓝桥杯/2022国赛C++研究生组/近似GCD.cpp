#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn],sum[maxn];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1];
        if(a[i]%k!=0)
            sum[i]++;
    }
    int pos=1,ans=0;
    for(int i=1;i<=n;i++){
        while(sum[pos]-sum[i-1]<=1&&pos<=n)
            pos++;
        ans+=pos-i-1;
    }
    cout<<ans;
    return 0;
}