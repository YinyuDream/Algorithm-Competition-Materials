#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,p,q;
int d[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
namespace low_size{
    int mapp[maxn][maxn];
    void work(int x,int y,int t){
        int mxk=max(n,m),nowk=-1;
        for(int i=1;i<=mxk;i++){
            for(int j=0;j<=7;j++){
                int nx=x+i*d[j][0],ny=y+i*d[j][1];
                if(!nx||!ny||nx>n||ny>m)return ;
            }
            for(int j=0;j<=7;j++){
                int nx=x+i*d[j][0],ny=y+i*d[j][1];
                if(mapp[nx][ny]){
                    nowk=i;
                    goto flag;
                }
            }
        }
        flag:;
        map<int,pair<int,int>>mp;
        for(int i=0;i<=7;i++){
            int nx=x+nowk*d[i][0],ny=y+nowk*d[i][1];
            if(mapp[nx][ny]){
                mp.insert(make_pair(mapp[nx][ny],make_pair(x+nowk*d[(i+t)%8][0],y+nowk*d[(i+t)%8][1])));
                mapp[nx][ny]=0;
            }
        }
        for(auto i:mp){
            int id=i.first;
            pair<int,int> pos=i.second;
            mapp[pos.first][pos.second]=id;
        }
    }
    void solve(){
        memset(mapp,0,sizeof mapp);
        for(int i=1;i<=p;i++){
            int x,y;
            cin>>x>>y;
            mapp[x][y]=i;
        }
        for(int i=1;i<=q;i++){
            int x,y,t;
            cin>>x>>y>>t;
            work(x,y,t);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(mapp[i][j])
                    ans^=(mapp[i][j]*i+j);
        cout<<ans;
    }
}
int main(){
    cin>>n>>m>>p>>q;
    low_size::solve();
    return 0;
}