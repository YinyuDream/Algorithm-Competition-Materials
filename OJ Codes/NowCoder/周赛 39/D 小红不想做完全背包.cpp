#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,p;
int f[maxn][maxn];
int a[maxn];
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++){
        f[i][a[i]%p]=1;
        for(int j=0;j<p;j++)
            f[i][j]=min(f[i][j],min(f[i-1][j],f[i-1][((j-a[i])%p+p)%p]+1));
    }
    cout<<f[n][0];
    return 0;
}