#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m,h;
struct node{
	int point,id;
	ll penalty;
}c[maxn];
bool cmp(node a,node b)
{
	if(a.point==b.point&&a.penalty==b.penalty)
		return a.id<b.id;
	return a.point!=b.point?a.point>b.point:a.penalty<b.penalty;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>h;
		vector<vector<ll>>a(n+1, vector<ll>(m+1, 0));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			sort(a[i].begin()+1,a[i].end());
		for(int i=1;i<=n;i++){
			c[i].id=i;
			for(int j=2;j<=m;j++)
				a[i][j]+=a[i][j-1];
			int pos=upper_bound(a[i].begin()+1,a[i].end(),h)-a[i].begin()-1;
			c[i].point=pos;
			for(int j=2;j<=m;j++)
				a[i][j]+=a[i][j-1];
			c[i].penalty=a[i][pos];
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(c[i].id==1)
				cout<<i<<endl;
	}
	return 0;
}