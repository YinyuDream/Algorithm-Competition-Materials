#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m,p,q,ans;
int mapp[maxn][maxn],edge[maxn][maxn],a[maxn][maxn],b[maxn][maxn];
int use[maxn],result[maxn];
bool dfs(int x,int t)
{
	for(int i=1;i<=q;i++){
		if(edge[x][i]&&use[i]!=t){
			use[i]=t;
			if(!result[i]||dfs(result[i],t)){
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch=getchar();
			while(ch!='*'&&ch!='.')
			ch=getchar();
			mapp[i][j]=(ch=='*');
		}
	}
	for(int i=1;i<=n;i++){
		if(mapp[i][1])a[i][1]=++p;
		for(int j=2;j<=m;j++){
			if(mapp[i][j]&&mapp[i][j-1])
			a[i][j]=a[i][j-1];
			else if(mapp[i][j]&&!mapp[i][j-1])
			a[i][j]=++p;
		}
	}
	for(int i=1;i<=m;i++){
		if(mapp[1][i])b[1][i]=++q;
		for(int j=2;j<=n;j++){
			if(mapp[j][i]&&mapp[j-1][i])
			b[j][i]=b[j-1][i];
			else if(mapp[j][i]&&!mapp[j-1][i])
			b[j][i]=++q;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mapp[i][j])
				edge[a[i][j]][b[i][j]]=1;
	for(int i=1;i<=p;i++)
		if(dfs(i,i))
			ans++;
	printf("%d",ans);
	return 0;
}
