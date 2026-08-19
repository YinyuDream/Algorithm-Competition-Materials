#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,ans=-0x3f3f3f3f;
int a[maxn][maxn],book[maxn][maxn],f[maxn][maxn];
int dx[]={-1,-1,-1},dy[]={-1,0,1};
void dfs(int x,int y)
{
	if(book[x][y])return ;
	book[x][y]=1;
	for(int i=0;i<=2;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<=n&&ny<=m&&nx>=1&&ny>=1)
		dfs(nx,ny);
	}
}
int main(){
	memset(f,-0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	dfs(n+1,(m+1)/2);
	f[n+1][(m+1)/2]=0;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
		{
			if(!book[i][j])continue;
			if(book[i+1][j])f[i][j]=max(f[i][j],f[i+1][j]);
			if(book[i+1][j-1])f[i][j]=max(f[i][j],f[i+1][j-1]);
			if(book[i+1][j+1])f[i][j]=max(f[i][j],f[i+1][j+1]);
			f[i][j]+=a[i][j];	
		}
	for(int i=1;i<=m;i++)
		if(book[1][i])
			ans=max(ans,f[1][i]);
	printf("%d",ans);
	return 0;
}
