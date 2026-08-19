#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int,int>a,pair<int,int>b){
		return -a.first+a.second<-b.first+b.second;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ll m;
	cin>>m;
	vector<pair<int,int>>v;
	vector<vector<int>>w;
	
	w.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b){
			swap(a,b);
		}
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<m;i++){
		w[v[i].first].push_back(v[i].second);
		w[v[i].second].push_back(v[i].first);
	}
	sort(v.begin(),v.end(),cmp);
	map<pair<int,int>,int>mp;
	for(int i=1;i<=n;i++){
		mp[{i,i}]=1;
	}
	ll ans=0;
	for(auto x:v){
		int a=x.first;
		int b=x.second;
		if(b==a+1){
			ans++;
			mp[{a,b}]=1;
		}
		else{
			if(mp[{a+1,b-1}]==0){
				continue;
			}
			int l=upper_bound(w[a].begin(),w[a].end(),a)-w[a].begin();
			int r=lower_bound(w[a].begin(),w[a].end(),b)-w[a].begin();
			int k=r-l;
			if(k==b-a-1){
				r=upper_bound(w[b].begin(),w[b].end(),b)-w[b].begin();
				l=lower_bound(w[b].begin(),w[b].end(),a)-w[b].begin();
				k=r-l-1;
				if(k==b-a-1){
					ans++;
					mp[{a,b}]=1;
				}
			}
		}
	}
	cout<<ans+n<<'\n';
	return 0;
}