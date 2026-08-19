#include<bits/stdc++.h>
using namespace std;
const int maxn=3e2+10,maxa=1e5+10;
int n,sum,ans=1e9;
int a[maxn];
bool f[maxn][maxa];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum/2;j++){
            f[i][j]|=f[i-1][j];
            if(j-a[i]>=0)
                f[i][j]|=f[i-1][j-a[i]];
        }
    }
    for(int i=0;i<=sum/2;i++){
        if(f[n][i]){
            ans=min(ans,abs(i-(sum-i)));
        }
    }
    cout<<ans;
    return 0;
}