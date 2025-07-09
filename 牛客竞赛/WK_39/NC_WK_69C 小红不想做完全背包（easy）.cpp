#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,p;
int f[maxn][3];
int a[maxn];
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++){
        f[i][a[i]%3]=1;
        f[i][0]=min(f[i][0],min(f[i-1][0],f[i-1][((0-a[i])%3+3)%3]+1));
        f[i][1]=min(f[i][1],min(f[i-1][1],f[i-1][((1-a[i])%3+3)%3]+1));
        f[i][2]=min(f[i][2],min(f[i-1][2],f[i-1][((2-a[i])%3+3)%3]+1));
    }
    cout<<f[n][0];
    return 0;
}