#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
long long sum,ans;
long long a[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ans=sum*sum;
    for(int i=1;i<=n;i++)
        ans-=a[i]*a[i];
    ans/=2;
    cout<<ans;
    return 0;
}