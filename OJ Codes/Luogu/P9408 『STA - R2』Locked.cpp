#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
int n,ans=0x3f3f3f3f;
int a[maxn],f[maxn][10],g[maxn][10];
int main(){
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=9;i++){
		f[1][i]=min(abs(a[1]-i),10-abs(a[1]-i));
		g[n][i]=min(abs(a[n]-i),10-abs(a[n]-i));
	}
	for(int i=1;i<=9;i++){
		f[1][i]=min(f[1][i],f[1][i-1]);
		g[n][i]=min(g[n][i],g[n][i-1]);
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++){
			f[i][j]=f[i-1][j]+min(abs(a[i]-j),10-abs(a[i]-j));
			if(j>=1)f[i][j]=min(f[i][j],f[i][j-1]);
		}
	}
	for(int i=n-1;i;i--){
		for(int j=0;j<=9;j++){
			g[i][j]=g[i+1][j]+min(abs(a[i]-j),10-abs(a[i]-j));
			if(j>=1)g[i][j]=min(g[i][j],g[i][j-1]);
		}
	}
	for(int i=1;i<n;i++){
		ans=min(ans,f[i][9]+g[i+1][9]);
	}
	cout<<ans<<endl;
	return 0;
}