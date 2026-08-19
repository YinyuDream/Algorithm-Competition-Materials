#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,w,s,ans=-0x7f7f7f7f,a[maxn],f[maxn][maxn];
int main(){
	memset(f,-0x7f,sizeof f);
	for(int i=0;i<=w;i++)
		f[0][i]=0;
	scanf("%d%d%d",&n,&w,&s);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=w&&j<=i;j++)
			for(int k=0;k<=s&&j+k-1<=w;k++)
				f[i][j]=max(f[i][j],f[i-1][j+k-1]+j*a[i]);
	for(int i=1;i<=w;i++)
		ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}