#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,n,m;
struct node{
	int pos,wt;
}a[maxn];
bool operator <(node u,node v)
{
	return u.pos<v.pos;
}
int cnt[maxn];
int l[maxn],r[maxn],in[maxn];
map<int,int>mp;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	cin>>c>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].pos>>a[i].wt;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		mp.insert(make_pair(a[i].pos,i));
		cnt[i]=a[i].wt;
		l[i]=i-1;
		r[i]=i+1;
	}
	r[n]=0;
	int tot=n;
	for(int i=1,pos;i<=m;i++){
		while(q.size())
			q.pop();
		cin>>pos;
		pos=mp[pos];
		cnt[pos]++;
		if(cnt[pos]>=5)
			q.push(pos),in[pos]=1;
		while(q.size()){
			int u=q.top();
			q.pop();
			tot--;
			if(l[u])r[l[u]]=r[u];
			if(r[u])l[r[u]]=l[u];
			if(l[u])cnt[l[u]]++;
			if(r[u])cnt[r[u]]++;
			if(l[u]&&cnt[l[u]]>=5&&!in[l[u]])q.push(l[u]),in[l[u]]=1;
			if(r[u]&&cnt[r[u]]>=5&&!in[r[u]])q.push(r[u]),in[r[u]]=1;
			l[u]=r[u]=0;
		}
		cout<<tot<<endl;
	}
	return 0;
}