#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans,mx_pos;
int a[maxn],b[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    mx_pos=a[1]+b[1];
    for(int i=2;i<=n;i++){
        if(a[i]-mx_pos>0)
            ans=max(ans,a[i]-mx_pos);
        mx_pos=max(mx_pos,a[i]+b[i]);
    }
    cout<<ans<<endl;
    return 0;
}