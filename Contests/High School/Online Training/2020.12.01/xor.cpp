#include<cstdio>
using namespace std;
const int maxn=2e3+10;
int n,m;
namespace subtask1{
	int mx,mp[maxn][maxn],ans[maxn][maxn];
	void update()
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				mp[i][j]^=mp[i-1][j]^mp[i][j-1]^mp[i-1][j-1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=i;k<=n;k++)
					for(int l=j;l<=m;l++)
						sum+=mp[k][l]^mp[k][j-1]^mp[i-1][l]^mp[i-1][j-1];
		if(sum>mx){
			mx=sum;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					ans[i][j]=mp[i][j];
		}
	}
	void dfs(int x,int y)
	{
		if(x==n+1){
			update();
			return ;
		}
		mp[x][y]=1;
		if(y==m)dfs(x+1,1);
		else dfs(x,y+1);
		mp[x][y]=0;
		if(y==m)dfs(x+1,1);
		else dfs(x,y+1);
	}
	void work(){
		n=(1<<n)-1,m=(1<<m)-1;
		dfs(1,1);
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++)
				printf("%d",ans[i][j]);
	}
}
namespace subtask2{
	void work(){
		n=(1<<n)-1,m=(1<<m)-1;
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++)
				printf("%d",(i^j^1)&1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=2&&m<=2)subtask1::work();
	else subtask2::work();
	return 0;
}
