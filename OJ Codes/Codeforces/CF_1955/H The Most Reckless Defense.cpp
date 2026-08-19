#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=51;
int T,n,m,k;
char s[maxn][maxn];
int val[maxn*maxn][13];
int pw3[maxn];
int f[maxn*maxn][1<<12];
int dis(int _x1,int _y1,int _x2,int _y2){
    return (_x1-_x2)*(_x1-_x2)+(_y1-_y2)*(_y1-_y2);
}
void work(int id,int x,int y,int p)
{
    for(int i=1;i<=12;i++){
        val[id][i]=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(s[j][k]=='#'&&dis(x,y,j,k)<=i*i){
                    val[id][i]++;
                }
            }
        }
        val[id][i]=val[id][i]*p-pw3[i];
    }
}
void solve()
{
    for(int i=1;i<=k;i++)
        for(int j=0;j<(1<<12);j++)
            f[i][j]=-0x3f3f3f3f;
    f[0][0]=0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<(1<<12);j++){
            f[i][j]=f[i-1][j];
            for(int k=1;k<=12;k++){
                if(j&(1<<(k-1))){
                    f[i][j]=max(f[i][j],f[i-1][j^(1<<(k-1))]+val[i][k]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<12);i++)
        ans=max(ans,f[k][i]);
    cout<<ans<<endl;
}
int main(){
    pw3[0]=1;
    for(int i=1;i<=12;i++)
        pw3[i]=pw3[i-1]*3;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>s[i]+1;
        for(int i=1;i<=k;i++){
            int x,y,p;
            cin>>x>>y>>p;
            work(i,x,y,p);
        }
        solve();
    }
    return 0;
}