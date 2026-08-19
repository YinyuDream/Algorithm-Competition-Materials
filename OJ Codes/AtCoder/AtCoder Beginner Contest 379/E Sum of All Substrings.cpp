#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> a(n+1),sum(n+1),ans(n+1);
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+i*a[i];
    }
    for(int i=0;i<=n;i++){
        ans[i]=sum[n-i];
    }
    for(int i=0;i<n;i++){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    int now=n;
    while(ans[now]>9){
        ans.push_back(ans[now]/10);
        ans[now]%=10;
        now++;
    }
    while(ans[now]==0){
        now--;
    }
    for(int i=now;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}