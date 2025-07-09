#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    k=n-k;
    vector<long long> a(n+1),sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    long long ans=0;
    for(int i=1;i+k-1<=n;i++){
        ans=max(ans,sum[i+k-1]-sum[i-1]);
    }
    cout<<ans<<endl;
}