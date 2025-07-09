#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n,m;
int c[maxn],d[maxn],l[maxn];
int f[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>d[i]>>c[i]>>l[i];
    memset(f,0x3f,sizeof f);
    for(int i=0;m-d[1]+i<=m&&i<=l[1];i++)
        f[1][m-d[1]+i]=i*c[1];
    for(int i=2;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=min(j,l[i]);k>=max(0,j-m+d[i]);k--)
                f[i][j]=min(f[i][j],f[i-1][j-k+d[i]]+c[i]*k);
    if(f[n][0]==0x3f3f3f3f)cout<<-1<<endl;
    else cout<<f[n][0]<<endl;
    return 0;
}