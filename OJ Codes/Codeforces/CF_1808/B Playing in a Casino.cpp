#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
ll ans;
vector<vector<int> >c,raw;
vector<vector<ll> > sum;
int main(){
	cin>>T;
	while(T--){
		raw.clear(),c.clear(),sum.clear(),ans=0;
		cin>>n>>m;
		raw.push_back(vector<int>());
		for(int i=1;i<=n;i++){
			raw.push_back(vector<int>());
			raw[i].push_back(0);
			for(int j=1,val;j<=m;j++){
				cin>>val;
				raw[i].push_back(val);
			}
		}
		c.push_back(vector<int>());
		sum.push_back(vector<ll>());
		for(int i=1;i<=m;i++){
			c.push_back(vector<int>());
			c[i].push_back(0);
			sum.push_back(vector<ll>());
			sum[i].push_back(0);
			for(int j=1;j<=n;j++){
				c[i].push_back(raw[j][i]);
				sum[i].push_back(0);
			}
		}
		for(int i=1;i<=m;i++){
			sort(c[i].begin()+1,c[i].end());
		}
		for(int i=1;i<=m;i++){
			sum[i][n]=c[i][n];
			for(int j=n-1;j;j--){
				sum[i][j]=sum[i][j+1]+c[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<n;j++){
				ans+=sum[i][j+1]-1ll*c[i][j]*(n-j);
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}