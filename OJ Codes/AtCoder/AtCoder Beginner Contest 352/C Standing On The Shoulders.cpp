#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,a[N],b[N];
ll sum,mx;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        mx=max(mx,1ll*b[i]-a[i]);
        sum+=a[i];
    }
    cout<<sum+mx<<endl;
    return 0;
}