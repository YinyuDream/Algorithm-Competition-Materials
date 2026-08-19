#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,ans;
char s[maxn];
int a[maxn][maxn],up[maxn][maxn],st[maxn],top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n%s",s+1);
		for(int j=1;j<=n;j++)
		a[i][j]=(s[j]=='W'?0:1);
	}
	for(int i=1;i<=n;i++)
		up[1][i]=(a[1][i]==0?1:-1);
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
			{
				if(a[j-1][i]==0&&a[j][i]==0)
				up[j][i]=up[j-1][i];
				else if(a[j-1][i]==1&&a[j][i]==0)
				up[j][i]=j;
				else up[j][i]=-1;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(up[i][j]!=-1)
				up[i][j]=i-up[i][j]+1;
	for(int i=1;i<=n;i++)//枚举行 
	{
		for(int j=1;j<=n;j++)//枚举列 
		{
			int minx=0x7f7f7f7f;
			for(int k=j;k<=n;k++)
			{
				if(up[i][k]==-1)break;
				minx=min(minx,up[i][k]);
				ans+=minx;	
			} 
		}
	}
	printf("%d",ans);
	return 0;
}
