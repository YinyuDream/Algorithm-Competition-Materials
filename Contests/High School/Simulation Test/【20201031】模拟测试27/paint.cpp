#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m,ans;
int a[maxn][maxn],book[maxn][maxn];
int size4[maxn],size8[maxn],belong4[maxn][maxn],belong8[maxn][maxn],flag[maxn],cnt4,cnt8;
int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,1,0,-1,1,-1,1,-1};
void dfs8(int x,int y,int c)
{
	size8[c]++;
	belong8[x][y]=c;
	book[x][y]=1;
	for(int i=0;i<=7;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(!book[nx][ny]&&nx>0&&ny>0&&nx<=n&&ny<=m&&a[nx][ny])
		dfs8(nx,ny,c);
	}
}
void dfs4(int x,int y,int c)
{
	size4[c]++;
	belong4[x][y]=c;
	book[x][y]=1;
	for(int i=0;i<=3;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(!book[nx][ny]&&nx>0&&ny>0&&nx<=n&&ny<=m&&a[nx][ny])
		dfs4(nx,ny,c);
	}
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char s[maxn];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][j]=s[j]=='1';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!book[i][j]&&a[i][j])
				dfs8(i,j,++cnt8);
	memset(book,0,sizeof book);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!book[i][j]&&a[i][j])
				dfs4(i,j,++cnt4);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(size4[belong4[i][j]]==size8[belong8[i][j]])
				flag[belong8[i][j]]=1;
	for(int i=1;i<=cnt8;i++)
		if(!flag[i])
			ans+=2;
	if(cnt8>1)ans++;
	printf("%d",ans);
	return 0;
}
