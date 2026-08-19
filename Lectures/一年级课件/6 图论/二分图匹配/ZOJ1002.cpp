#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 50
char map[N][N];
int fuck[N][N],n,m,vis[N],match[N];
vector <int> G[N];
void Handle() {
    int cnt=1;
    for(int j=1;j<=n;j++) {
        int flag=0;
        for(int i=1;i<=n;i++) {
            if(map[i][j]!='X')
                fuck[i][j]=cnt,flag=0;
            else if(map[i-1][j]!='X')
                cnt++,flag=1;
        }
        cnt++;
    }
          
    m=cnt;cnt++;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(map[i][j]!='X')
                G[fuck[i][j]].push_back(cnt);
            else if(map[i][j-1]!='X')
                cnt++;
        }
        cnt++;
    }
          
}
  
bool dfs(int u) {
    for(int i=0,v;i<G[u].size();i++) {
        v=G[u][i];
        if(vis[v]) continue;
        vis[v]=1;
        if( !match[v] || dfs( match[v] )) {
            match[v]=u; 
            return 1;
        }
    }
    return 0;
}
   
int hungary() {
    int ans=0;
    for(int i=1;i<=m;i++) {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}
  
int main() {
    cin>>n;
    for(int i=1;i<=n;i++ ) for(int j=1;j<=n;j++)
        cin>>map[i][j];
    Handle();
    cout<<hungary();
}
