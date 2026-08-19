#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,ans,cnt;
int a[maxn][maxn],book[maxn][maxn];
int nx[4]={0,0,1,-1},ny[4]={1,-1,0,0};
int work(int x,int y)
{
    cnt++;
    int res=1;
    queue<pair<int,int>>q;
    q.push(make_pair(x,y));
    book[x][y]=cnt;
    while(q.size()){
        pair<int,int>u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int dx=u.first+nx[i],dy=u.second+ny[i];
            if(dx<1||dx>n||dy<1||dy>m||a[dx][dy]==-1||book[dx][dy]==cnt) continue;
            book[dx][dy]=cnt;
            res++;
            if(a[dx][dy]==0)q.push(make_pair(dx,dy));
        }
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch=getchar();
            while(ch!='.'&&ch!='#') ch=getchar();
            if(ch=='.') a[i][j]=0;
            else a[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==0&&(a[i][j-1]==-1||a[i-1][j]==-1||a[i+1][j]==-1||a[i][j+1]==-1))
                a[i][j]=1,ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0&&!book[i][j]){
                ans=max(ans,work(i,j));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}