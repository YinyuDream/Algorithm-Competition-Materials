#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,Q;
int mp[maxn][maxn],mapp[maxn][maxn],mn[maxn][maxn],f[maxn][maxn];
void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
}
bool check(int day)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mapp[i][j]=mp[i][j];
    for(int i=1;i<=day%n;i++)
        for(int j=1;j<=n;j++)
            mapp[i][j]=mapp[j][i]=max(mapp[i][j]-day/n-1,mn[i][j]);
    for(int i=day%n+1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mapp[i][j]=mapp[j][i]=max(mapp[i][j]-day/n,mn[i][j]);
    solve();
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans+=mapp[i][j];
    return ans<=Q;
}
int main(){
    cin>>n>>Q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mn[i][j];
    int l=0,r=(1<<31)-2;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    check(2);
    if(l==(1<<31)-1)cout<<-1;
    else cout<<l;
    return 0;
}