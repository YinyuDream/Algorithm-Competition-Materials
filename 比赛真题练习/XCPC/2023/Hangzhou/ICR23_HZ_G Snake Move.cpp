#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn=5e3+10;
int n,m,k;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int a[maxn][maxn],f[maxn][maxn],book[maxn][maxn];
ull ans;
struct node{
    int x,y;
    int step;
};
bool operator<(node a,node b){
    return a.step>b.step;
}
priority_queue<node>q;
int main(){
    memset(f,0x3f,sizeof(f));
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=i;
        if(i==1){
            q.push({x,y,0});
            f[x][y]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch=getchar();
            while(ch!='.'&&ch!='#')ch=getchar();
            if(ch=='#')a[i][j]=-1;
        }
    }
    while(q.size()){
        node u=q.top();
        q.pop();
        int x=u.x,y=u.y;
        if(book[x][y])continue;
        book[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(a[nx][ny]==-1)continue;
            if(nx<1||nx>n||ny<1||ny>m||book[nx][ny])continue;
            int nd=a[nx][ny]?(f[x][y]+1>=k-a[nx][ny]+1?f[x][y]+1:k-a[nx][ny]+1):f[x][y]+1;
            if(f[nx][ny]>nd){
                f[nx][ny]=nd;
                q.push({nx,ny,nd});
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j]!=0x3f3f3f3f)
                ans+=1ull*f[i][j]*f[i][j];
    cout<<ans<<endl;
    return 0;
}