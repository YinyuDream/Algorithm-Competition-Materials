#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+10;
int n,m,A,B;
int a[maxn],b[maxn],g[5][5],f[maxn][maxn][3];
char _a[maxn],_b[maxn];
int main(){
	memset(f,-0x7f,sizeof f);
	f[0][0][2]=0;
	scanf("%s\n%s",_a+1,_b+1);
	n=strlen(_a+1),m=strlen(_b+1);
	for(int i=1;i<=n;i++){
		if(_a[i]=='A')a[i]=1;
		if(_a[i]=='T')a[i]=2;
		if(_a[i]=='G')a[i]=3;
		if(_a[i]=='C')a[i]=4;
	}
	for(int i=1;i<=m;i++){
		if(_b[i]=='A')b[i]=1;
		if(_b[i]=='T')b[i]=2;
		if(_b[i]=='G')b[i]=3;
		if(_b[i]=='C')b[i]=4;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			scanf("%d",&g[i][j]);
	scanf("%d%d",&A,&B);
	for(int i=1;i<=n;i++)
		f[i][0][1]=-A-B*(i-1);
	for(int i=1;i<=m;i++)
		f[0][i][0]=-A-B*(i-1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j][0]=max(max(f[i][j-1][2]-A,f[i][j-1][1]-A),f[i][j-1][0]-B),
			f[i][j][1]=max(max(f[i-1][j][2]-A,f[i-1][j][0]-A),f[i-1][j][1]-B),
			f[i][j][2]=g[a[i]][b[j]]+max(max(f[i-1][j-1][0],f[i-1][j-1][1]),f[i-1][j-1][2]);
	printf("%d\n",max(max(f[n][m][0],f[n][m][1]),f[n][m][2]));
	return 0;
}