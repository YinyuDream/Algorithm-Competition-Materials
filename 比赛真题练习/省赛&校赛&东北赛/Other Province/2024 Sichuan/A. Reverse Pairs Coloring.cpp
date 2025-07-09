#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans;
int a[maxn],pos[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],pos[a[i]]=i;
    for(int i=1;i<=n;i++){
        int l=pos[a[i]-1],r=pos[a[i]];
        for(int j=l;j<=r;j++){
            if(a[j-1]<a[i]&&a[i]<a[j])
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}