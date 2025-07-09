#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
int a[maxn],sum[maxn];
ll ans1,ans2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        sum[l]++;
        sum[r+1]--;
    }
    for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++)
        ans1+=1ll*sum[i]*a[i];
    sort(a+1,a+n+1);
    sort(sum+1,sum+n+1);
        for(int i=1;i<=n;i++)
        ans2+=1ll*sum[i]*a[i];
    cout<<ans2-ans1;
    return 0;
}