#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m,qx,qy,zx,zy;
int dx[4]={-1,1,1,-1};
int dy[4]={-1,1,-1,1};
struct node{
    int x,y,dir;
    node(int _x,int _y,int _dir){
        x=_x,y=_y,dir=_dir;
    }
};
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>qx>>qy>>zx>>zy;
        string s;
        cin>>s;
        int d;
        if(s=="UL")d=1;//左上
        else if(s=="DR")d=2;//右下
        else if(s=="DL")d=3;//左下
        else d=4;//右上
        vector<vector<vector<int>>> dis(5, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        queue<node>q;
        q.push(node(qx,qy,d));
        dis[d][qx][qy]=0;
        while(q.size()){
            node u=q.front();
            q.pop();
            if(u.dir==1){
                int nx,ny,ndir,flag=1;
                if(u.x==1&&u.y==1){
                    nx=ny=2;
                    ndir=2;
                }else if(u.x==1&&u.y!=1){
                    nx=2,ny=u.y-1;
                    ndir=3;
                }else if(u.x!=1&&u.y==1){
                    nx=u.x-1,ny=2;
                    ndir=4;
                }else{
                    nx=u.x-1,ny=u.y-1;
                    ndir=1;
                    flag=0;
                }
                if(dis[ndir][nx][ny]==-1){
                    if(flag)dis[ndir][nx][ny]=dis[u.dir][u.x][u.y]+1;
                    else dis[ndir][nx][ny]=dis[u.dir][u.x][u.y];
                    q.push(node(nx,ny,ndir));
                }
            }else if(u.dir==2){
                int nx,ny,ndir,flag=1;
                if(u.x==n&&u.y==m){
                    nx=n-1,ny=m-1;
                    ndir=1;
                }else if(u.x==n&&u.y!=m){
                    nx=n-1,ny=u.y+1;
                    ndir=4;
                }else if(u.x!=n&&u.y==m){
                    nx=u.x+1,ny=m-1;
                    ndir=3;
                }else{
                    nx=u.x+1,ny=u.y+1;
                    ndir=2;
                    flag=0;
                }
                if(dis[ndir][nx][ny]==-1){
                    if(flag)dis[ndir][nx][ny]=dis[u.dir][u.x][u.y]+1;
                    else dis[ndir][nx][ny]=dis[u.dir][u.x][u.y];
                    q.push(node(nx,ny,ndir));
                }
            }else if(u.dir==3){
                int nx,ny,ndir,flag=1;
                if(u.x==n&&u.y==1){
                    nx=n-1,ny=2;
                    ndir=4;
                }else if(u.x==n&&u.y!=1){
                    nx=n-1,ny=u.y-1;
                    ndir=1;
                }else if(u.x!=n&&u.y==1){
                    nx=u.x+1,ny=2;
                    ndir=2;
                }else{
                    nx=u.x+1,ny=u.y-1;
                    ndir=3;
                    flag=0;
                }
                if(dis[ndir][nx][ny]==-1){
                    if(flag)dis[ndir][nx][ny]=dis[u.dir][u.x][u.y]+1;
                    else dis[ndir][nx][ny]=dis[u.dir][u.x][u.y];
                    q.push(node(nx,ny,ndir));
                }
            }else{
                int nx,ny,ndir,flag=1;
                if(u.x==1&&u.y==m){
                    nx=2,ny=m-1;
                    ndir=3;
                }else if(u.x==1&&u.y!=m){
                    nx=2,ny=u.y+1;
                    ndir=2;
                }else if(u.x!=1&&u.y==m){
                    nx=u.x-1,ny=m-1;
                    ndir=1;
                }else{
                    nx=u.x-1,ny=u.y+1;
                    ndir=4;
                    flag=0;
                }
                if(dis[ndir][nx][ny]==-1){
                    if(flag)dis[ndir][nx][ny]=dis[u.dir][u.x][u.y]+1;
                    else dis[ndir][nx][ny]=dis[u.dir][u.x][u.y];
                    q.push(node(nx,ny,ndir));
                }
            }
        }
        int ans=1e9;
        for(int i=1;i<=4;i++){
            if(dis[i][zx][zy]!=-1){
                ans=min(ans,dis[i][zx][zy]);
            }
        }
        if(ans==1e9)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}