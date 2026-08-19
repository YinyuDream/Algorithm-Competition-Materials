#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n,m;
char a[maxn],b[maxn];
int f[maxn][maxn];
int main(){
	scanf("%s\n%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	printf("%d",f[n][m]);
	return 0;
}
