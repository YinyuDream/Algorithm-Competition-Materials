#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n,m;
int a[maxn][maxn],b[maxn][maxn],can[maxn][maxn];
ll f[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>b[i][j];
    f[1][1]=b[1][1],can[1][1]=1;
    for(int i=2;i<=n;i++){
        f[i][1]=f[i-1][1]+b[i][1];
        if(can[i-1][1]&&a[i][1]-a[1][1]-f[i][1]>=0)
            can[i][1]=1;
    }
    for(int i=2;i<=m;i++){
        f[1][i]=f[1][i-1]+b[1][i];
        if(can[1][i-1]&&a[1][i]-a[1][1]-f[1][i]>=0)
            can[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(can[i][j-1]&&a[i][j]-a[1][1]-f[i][j-1]-b[i][j]>=0)
                can[i][j]=1;
            if(can[i-1][j]&&a[i][j]-a[1][1]-f[i-1][j]-b[i][j]>=0)
                can[i][j]=1;
            f[i][j]=min(f[i-1][j],f[i][j-1])+b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(can[i][m]){
            cout<<"YES";
            return 0;
        }
    }
    for(int i=1;i<=m;i++){
        if(can[n][i]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}