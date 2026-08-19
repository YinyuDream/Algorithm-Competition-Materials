#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i%2==0){
            a.push_back(x);
        }else{
            b.push_back(x);
        }
    }
    int k;
    cin>>k;
    ll ans=0;
    vector<ll> sum(a.size());
    for(int i=0;i<a.size();i++){
        sum[i]=a[i];
        if(i){
            sum[i]+=sum[i-1];
        }
    }
    for(int i=k-1;i<a.size();i++){
        ans=max(ans,sum[i]-sum[i-k+1]+a[i-k+1]);
    }
    sum.resize(b.size());
    for(int i=0;i<b.size();i++){
        sum[i]=b[i];
        if(i){
            sum[i]+=sum[i-1];
        }
    }
    for(int i=k-1;i<b.size();i++){
        ans=max(ans,sum[i]-sum[i-k+1]+b[i-k+1]);
    }
    cout<<ans<<endl;
    return 0;
}