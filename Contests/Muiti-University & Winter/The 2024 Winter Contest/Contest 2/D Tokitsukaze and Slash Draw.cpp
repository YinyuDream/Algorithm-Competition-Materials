#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int to,next;
    ll wt;
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<node> edge(n*m+1);
    vector<int> head(n+1);
    int cnt_edge=0;
    auto add=[&](int u,int v,ll w){
        edge[++cnt_edge]={v,head[u],w};
        head[u]=cnt_edge;
    };
    for(int i=1;i<=m;i++){
        int a;
        ll b;
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            add(i,(i+a-1)%n+1,b);
        }
    }
    priority_queue<pair<ll,int>> q;
    vector<int> book(n+1);
    vector<ll> dis(n+1,1e17);
    q.push({0,k});
    dis[k]=0;
    while(q.size()){
		int u=q.top().second;
		q.pop();
		if(book[u])continue;
		book[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(book[v]==0&&dis[v]>dis[u]+edge[i].wt){
				dis[v]=dis[u]+edge[i].wt;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
    if(dis[n]==1e17){
        dis[n]=-1;
    }
    cout<<dis[n]<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}