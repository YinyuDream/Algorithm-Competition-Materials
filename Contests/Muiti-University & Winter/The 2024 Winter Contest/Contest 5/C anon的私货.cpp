#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn],b[maxn];
long long ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ans+=a[1]-1;
    b[1]=a[1]-1;
    for(int i=2;i<=n;i++){
        b[i]=min(a[i-1]-b[i-1]-1,a[i]-1);
        ans+=b[i];
    }
    ans+=a[n]-b[n]-1;
    cout<<ans;
    return 0;
}