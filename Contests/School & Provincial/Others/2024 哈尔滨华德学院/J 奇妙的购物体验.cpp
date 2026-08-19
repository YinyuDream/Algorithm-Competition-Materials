#include<bits/stdc++.h>
using namespace std;
const int maxn=21,maxm=2e3+10;
int n,m,k,shabu,ldz,tot;
int dis[maxn][maxn],f[1<<maxn][maxn];
int v[15*maxm],w[15*maxm];
int g[2][maxm];
int dp()
{
    memset(f,0x3f,sizeof f);
    for(int i=0;i<=(1<<n)-1;i++){
        for(int j=1;j<=n;j++){
            if(i==(1<<j-1))f[i][j]=dis[1][j];
            else if(i&(1<<j-1)){
                for(int k=1;k<=n;k++){
                    if(((1<<k-1)&i)&&k!=j){
                        f[i][j]=min(f[i][j],f[i^(1<<j-1)][k]+dis[k][j]);
                    }
                }
            }
        } 
    }
    int ans=0x3f3f3f3f;
    for(int i=2;i<=n;i++)
        ans=min(ans,f[(1<<n)-1][i]+dis[i][1]);
    return ans;
}
void work(int num,int val,int wt)
{
    int c=1;
    while(num>c) {
        num-=c;
        w[++tot]=c*wt;
        v[tot]=c*val;
        c*=2;
      }
      w[++tot]=num*wt;
      v[tot]=num*val;
}
int main(){
    cin>>n>>m>>k>>shabu>>ldz;
    memset(dis,0x3f,sizeof f);
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        dis[y][x]=dis[x][y]=min(dis[x][y],z);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int ans1=dp();
    cout<<ans1<<endl;
    if(ans1>=shabu){
        cout<<"Shub, go work overtime!";
        return 0;
    }
    shabu-=ans1;
    for(int i=1;i<=k;i++){
        int num,val,wt;
        cin>>num>>val>>wt;
        work(num,val,wt);
    }
    for(int i=1;i<=tot;i++){
        for(int j=0;j<=shabu;j++){
            g[i&1][j]=g[(i-1)&1][j];
            if(j-v[i]>=0)
                g[i&1][j]=max(g[i&1][j],g[(i-1)&1][j-v[i]]+w[i]);
        }
    }
    int ans2=g[tot&1][shabu];
    cout<<ans2<<endl;
    if(ans2>ldz)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}