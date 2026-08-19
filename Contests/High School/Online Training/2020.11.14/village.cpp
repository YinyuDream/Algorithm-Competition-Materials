#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int maxn=1e3+10;
int n,m,cnt,ans;
int a[maxn][maxn],book[maxn][maxn];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct node{
	int mnx,mny,mxx,mxy;
}p[maxn];
bool bfs(int x,int y)
{
	int mnx=x,mxx=x,mny=y,mxy=y;
	queue<pii>q;
	q.push(make_pair(x,y));
	book[x][y]=1;
	while(!q.empty()){
		pii u=q.front();
		q.pop();
		for(int i=0;i<=3;i++){
			int nx=u.first+dx[i],ny=u.second+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!book[nx][ny]&&!a[nx][ny]){
				mnx=min(mnx,nx);
				mxx=max(mxx,nx);
				mny=min(mny,ny);
				mxy=max(mxy,ny);
				book[nx][ny]=1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	if(mnx>1&&mxx<n&&mny>1&&mxy<m)
		p[++cnt]=(node){mnx,mny,mxx,mxy};
}
int sumx[maxn][maxn],sumy[maxn][maxn],sumc[maxn][maxn],sump[maxn][maxn];
int getsum(int mnx,int mny,int mxx,int mxy)
{
	int sum=0;
	sum+=sump[mxx][mxy]-sump[mnx-1][mxy]-sump[mxx][mny-1]+sump[mnx-1][mny-1];
	sum+=sumc[mxx][mxy]-sumc[mnx][mxy]-sumc[mxx][mny]+sumy[mnx][mny];
	sum-=sumx[mxx][mxy]-sumx[mnx-1][mxy]-sumx[mxx][mny]+sumx[mnx-1][mny];
	sum-=sumy[mxx][mxy]-sumy[mnx][mxy]-sumy[mxx][mny-1]+sumy[mnx][mny-1];
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch=getchar();
			while(ch!='0'&&ch!='1')ch=getchar();
			a[i][j]=ch=='1';
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j]&&!book[i][j])
				bfs(i,j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sump[i][j]=sump[i-1][j]+sump[i][j-1]-sump[i-1][j-1]+a[i][j];
			sumc[i][j]=sumc[i-1][j]+sumc[i][j-1]-sumc[i-1][j-1]+(a[i][j]+a[i][j-1]+a[i-1][j]+a[i-1][j-1]==4);
			sumx[i][j]=sumx[i-1][j]+sumx[i][j-1]-sumx[i-1][j-1]+(a[i][j]+a[i][j-1]==2);
			sumy[i][j]=sumy[i-1][j]+sumy[i][j-1]-sumy[i-1][j-1]+(a[i][j]+a[i-1][j]==2); 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int r=1,l=0;r<=m;r++){
				while(getsum(i,l,j,k)>1)l++;
				ans+=r-l;
			}
		}
	}
	return 0;
}
