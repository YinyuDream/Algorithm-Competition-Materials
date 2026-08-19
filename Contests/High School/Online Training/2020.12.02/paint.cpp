#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m,k;
int a[maxn][maxn],book[maxn][maxn];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
queue<pair<int,int> >q;
void update(int x,int y,int w)
{
	int col=a[x][y];
	q.push(make_pair(x,y));
	memset(book,0,sizeof book);
	while(!q.empty()){
		pair<int,int> u=q.front();
		a[u.first][u.second]=w;
		q.pop();
		for(int i=0;i<=3;i++){
			int nx=u.first+dx[i],ny=u.second+dy[i];
			if(nx<1||ny<1||nx>n||ny>m||book[nx][ny])continue;
			if(a[nx][ny]==col)q.push(make_pair(nx,ny)),book[nx][ny]=1;
		}
	}
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d",&k);
	for(int i=1,u,v,w;i<=k;i++){
		scanf("%d%d%d",&u,&v,&w);
		update(u,v,w);
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
	return 0;
}
