#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,ans=1;
map<string,int>mp;
int f[maxn][maxn],g[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		mp[s]=i;
	}
	for(int i=1,st,ed;i<=m;i++){
		string u,v;
		cin>>u>>v;
		st=mp[u],ed=mp[v];
		g[st][ed]=g[ed][st]=1;
	}
	f[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<j;k++)
				if(g[j][k]&&f[i][k])
					f[j][i]=f[i][j]=max(f[i][j],f[i][k]+1);
	for(int i=1;i<=n;i++)
		if(g[i][n])
			ans=max(ans,f[i][n]);
	printf("%d",ans);
	return 0;
}