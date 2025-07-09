#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
int a[maxn][maxn],dis[maxn][maxn],book[maxn][maxn];
queue<pair<int,int>>q;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
    cin>>n>>m;
    if(n==m&&n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch=getchar();
            while(ch<'a'||ch>'z')
                ch=getchar();
            a[i][j]=ch-'a';
        }
    }
    q.push(make_pair(1,1));
    book[1][1]=1;
    while(q.size()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<=3;i++){
            int nx=u.first+dx[i],ny=u.second+dy[i];
            if(nx>n||ny>m||nx<=0||ny<=0||book[nx][ny]||a[u.first][u.second]==a[nx][ny])
                continue;
            book[nx][ny]=1;
            dis[nx][ny]=dis[u.first][u.second]+1;
            q.push(make_pair(nx,ny));
        }
    }
    if(dis[n][m]==0)
        cout<<-1;
    else
        cout<<dis[n][m];
    return 0;
}