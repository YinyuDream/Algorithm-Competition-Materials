#include <iostream>
using namespace std;
int dp[101][101][10102];
int v[200];
int w[200];
void solve(){
	int n,m;
	cin>>n;
	m=n;
	int all=0;
	int nn,mm;
	nn=mm=0;
	int at=0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		all-=(i+1)*t;
		if(t==1){
			v[nn++]=i+1;
			at+=i+1;
		}
	}
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		all+=(i+1)*t;
		if(t==2){
			w[mm++]=i+1;
			at+=i+1;
		}
	}
	if(all==0){
		cout<<0<<'\n';
		return;
	}
	if(all<0||nn==0||mm==0||all>10100||all>at){
		cout<<-1<<'\n';
		return;
	}
	n=nn;
	m=mm;
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=all;k++){
				dp[i][j][k]=500;
			}
		}
	}
	for(int i=0;i<=n;i++){
		dp[i][0][all]=0;
	}
	for(int i=0;i<=m;i++){
		dp[0][i][all]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=all;k++){
				dp[i][j][k]=min(dp[i-1][j][k],dp[i][j-1][k]);
				if(k+v[i-1]+w[j-1]<=all){
					dp[i][j][k]=min(dp[i-1][j-1][k+v[i-1]+w[j-1]]+1,dp[i][j][k]);
				}
				
			}
		}
	}
	if(dp[n][m][0]<500){
		cout<<dp[n][m][0]<<'\n';
	}
	else{
		cout<<"-1\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}