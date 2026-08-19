#include<bits/stdc++.h>
using namespace std;
const int maxn=210,maxm=1e5+10;
int n,m;
int p[maxn],v[maxn],sz[maxm];
int f[maxn][maxn][maxn],g[maxn][maxm];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>p[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=0;k<maxn;k++){
                f[i][j][k]=f[i][j-1][k];
                if(k>=p[j])
                    f[i][j][k]=max(f[i][j][k],f[i][j-1][k-p[j]]+v[j]);
            }
        }
    }
    for(int i=1;i<=m;i++)
        cin>>sz[i];
    for(int i=1;i<=n;i++){
        for(int j=max(m-n+1,1);j<=m;j++){
            g[i][j]=f[1][i][sz[j]];
            for(int k=1;k<i;k++){
                g[i][j]=max(g[i][j],g[k][j-1]+f[k+1][i][sz[j]]);
            }
        }
    }
    cout<<g[n][m];
    return 0;
}