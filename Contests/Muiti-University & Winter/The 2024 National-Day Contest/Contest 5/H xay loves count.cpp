#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int mx=*max_element(a.begin(),a.end());
    vector<int> cnt(mx+1);
    long long ans=0;
    for(int i=0;i<n;i++)
        cnt[a[i]]++;
    for(int i=1;i<=mx;i++){
        for(int j=1;j*i<=mx;j++){
            ans+=1ll*cnt[i]*cnt[j]*cnt[i*j];
        }
    }
    cout<<ans;
    return 0;
}