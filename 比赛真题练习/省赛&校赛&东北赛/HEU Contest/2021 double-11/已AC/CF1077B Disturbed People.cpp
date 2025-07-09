#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,ans=0x7f7f7f7f;
int a[maxn],f[maxn][2][2];
int main(){
	memset(f,0x7f,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(a[1]){
		f[1][1][0]=f[1][1][1]=0;
		f[1][0][1]=f[1][0][0]=1;
	}else{
		f[1][0][1]=f[1][0][0]=0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]){
			f[i][0][0]=min(f[i-1][0][0],f[i-1][0][1])+1;
			f[i][0][1]=min(f[i-1][1][0],f[i-1][1][1])+1;
			f[i][1][1]=min(f[i-1][1][0],f[i-1][1][1]);
			f[i][1][0]=f[i-1][0][0];
		}else{
			f[i][0][0]=min(f[i-1][0][0],f[i-1][0][1]);
			f[i][0][1]=min(f[i-1][1][0],f[i-1][1][1]);
		}
	}
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			ans=min(ans,f[n][i][j]);
	printf("%d",ans);
	return 0;
}