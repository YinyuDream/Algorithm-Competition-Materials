#include<bits/stdc++.h>
using ll = long long;
using namespace std;
char mp[3004][3005];
int ans[3004][3004][4];
int book[3004][3004];
int all=0;
int alll;
int t=0;
int n,m;
void dfs(int a,int b,int c){
	if(ans[a][b][c]==-1){
		t=1;
		alll=all;
		return;
	}
//	cout<<all<<' ';
	if(a>n||b>m||a<=0||b<=0){
		return;
	}
	ans[a][b][c]=-1;
	if(c==0||c==1){
		if(mp[a][b]!='|'){
			book[a][b]++;
			if(book[a][b]==1){
				all++;
			}
		}
	}
	if(c==2||c==3){
		if(mp[a][b]!='-'){
			book[a][b]++;
			if(book[a][b]==1){
				all++;
			}  
		}
	}
	if(c==0){
		if(mp[a][b]=='/'){
			dfs(a,b+1,2);
		}
		if(mp[a][b]=='|'){
			dfs(a-1,b,0);
		}
		if(mp[a][b]=='-'){
			dfs(a+1,b,1);
		}
		if(mp[a][b]=='\\'){
			dfs(a,b-1,3);
		}
	}
	if(c==1){
		if(mp[a][b]=='/'){
			dfs(a,b-1,3);
		}
		if(mp[a][b]=='|'){
			dfs(a+1,b,1);
		}
		if(mp[a][b]=='-'){
			dfs(a-1,b,0);
		}
		if(mp[a][b]=='\\'){
			dfs(a,b+1,2);
		}
	}
	if(c==2){
		if(mp[a][b]=='/'){
			dfs(a-1,b,0);
		}
		if(mp[a][b]=='|'){
			dfs(a,b-1,3);
		}
		if(mp[a][b]=='-'){
			dfs(a,b+1,2);
		}
		if(mp[a][b]=='\\'){
			dfs(a+1,b,1);
		}
	}
	if(c==3){
		if(mp[a][b]=='/'){
			dfs(a+1,b,1);
		}
		if(mp[a][b]=='|'){
			dfs(a,b+1,2);
		}
		if(mp[a][b]=='-'){
			dfs(a,b-1,3);
		}
		if(mp[a][b]=='\\'){
			dfs(a-1,b,0);
		}
	}
	if(t==1){
		ans[a][b][c]=alll;
	if(c==0||c==1){
		if(mp[a][b]!='|'){
			book[a][b]--;
			if(book[a][b]==0){
				all--;
			}
		}
	}
	if(c==2||c==3){
		if(mp[a][b]!='-'){
			book[a][b]--;
			if(book[a][b]==0){
				all--;
			}
		}
	}
	}
}
void dfss(int a,int b,int c){
	if(a>n||b>m||a<=0||b<=0){
		return;
	}
//	cout<<all<<' ';
	ans[a][b][c]=all;
	if(c==0||c==1){
		if(mp[a][b]!='|'){
			book[a][b]--;
			if(book[a][b]==0){
				all--;
			}
		}
	}
	if(c==2||c==3){
		if(mp[a][b]!='-'){
			book[a][b]--;
			if(book[a][b]==0){
				all--;
			}
		}
	}
	if(c==0){
		if(mp[a][b]=='/'){
			dfss(a,b+1,2);
		}
		if(mp[a][b]=='|'){
			dfss(a-1,b,0);
		}
		if(mp[a][b]=='-'){
			dfss(a+1,b,1);
		}
		if(mp[a][b]=='\\'){
			dfss(a,b-1,3);
		}
	}
	if(c==1){
		if(mp[a][b]=='/'){
			dfss(a,b-1,3);
		}
		if(mp[a][b]=='|'){
			dfss(a+1,b,1);
		}
		if(mp[a][b]=='-'){
			dfss(a-1,b,0);
		}
		if(mp[a][b]=='\\'){
			dfss(a,b+1,2);
		}
	}
	if(c==2){
		if(mp[a][b]=='/'){
			dfss(a-1,b,0);
		}
		if(mp[a][b]=='|'){
			dfss(a,b-1,3);
		}
		if(mp[a][b]=='-'){
			dfss(a,b+1,2);
		}
		if(mp[a][b]=='\\'){
			dfss(a+1,b,1);
		}
	}
	if(c==3){
		if(mp[a][b]=='/'){
			dfss(a+1,b,1);
		}
		if(mp[a][b]=='|'){
			dfss(a,b+1,2);
		}
		if(mp[a][b]=='-'){
			dfss(a,b-1,3);
		}
		if(mp[a][b]=='\\'){
			dfss(a-1,b,0);
		}
	}
}
void solve()
{
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				ans[i][j][k]=-2;
			}
		}
	}
	ll q;
	cin>>q;
		for(int j=1;j<=m;j++){
			if(ans[1][j][1]==-2){
			//	all=0;
				t=0;
				dfs(1,j,1);
				dfss(1,j,1);
			}
			if(ans[n][j][0]==-2){
		//		all=0;
				t=0;
				dfs(n,j,0);
				dfss(n,j,0);
			}
		}
		for(int j=1;j<=m;j++){
			if(ans[j][1][2]==-2){
		//		all=0;
				t=0;
				dfs(j,1,2);
				dfss(j,1,2);
			}
			if(ans[j][m][3]==-2){
			//	all=0;
				t=0;
				dfs(j,m,3);
				dfss(j,m,3);
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++)
				if(ans[i][j][k]==-2){
			//	all=0;
				t=0;
				dfs(i,j,k);
			}
		}
	}
	map<string,int>mp;
	mp["above"]=0;
	mp["below"]=1;
	mp["right"]=2;
	mp["left"]=3;
	while(q--){
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		int c=mp[s];
		if(c==0){
			cout<<ans[a-1][b][0];
		}
		if(c==1){
			cout<<ans[a+1][b][1];
		}
		if(c==2){
			cout<<ans[a][b+1][2];
		}
		if(c==3){
			cout<<ans[a][b-1][3];
		}
		cout<<'\n';
	}
	
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t = 1;
	//	cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}