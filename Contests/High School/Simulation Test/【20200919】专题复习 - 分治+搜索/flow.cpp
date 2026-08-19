#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=5e2+10;
int n,m,l[maxn][maxn],r[maxn][maxn],map[maxn][maxn],book[maxn][maxn],cnt,lmax,ans;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
struct node{
    int l,r;
}e[maxn];
bool cmp(node a,node b)
{
    return a.l<b.l;
}
void dfs(int x,int y){
    book[x][y]=1;
    for(int i=0;i<=3;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m||map[nx][ny]>=map[x][y])continue;
        if(book[nx][ny]==0) dfs(nx,ny);
        l[x][y]=min(l[x][y],l[nx][ny]),r[x][y]=max(r[x][y],r[nx][ny]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(l,0x3f,sizeof(l));
    for(int i=1;i<=m;i++)
        l[n][i]=r[n][i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    for(int i=1;i<=m;i++) 
        if(book[1][i]==0)
            dfs(1,i);
    for(int i=1;i<=m;i++)cnt+=!book[n][i];
    if(cnt)return printf("0\n%d",cnt),0;
    lmax=1;
    while(lmax<=m)
    {
    	int rmax=0;
        for(int i=1;i<=m;i++)
        if(l[1][i]<=lmax)
        rmax=max(rmax,r[1][i]);
        lmax=rmax+1;
        ans++;
    }
    printf("1\n%d",ans);
    return 0;
}
