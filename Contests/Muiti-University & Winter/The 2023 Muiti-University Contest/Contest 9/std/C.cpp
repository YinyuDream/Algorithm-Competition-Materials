#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000; /////////////////////
const int inf  = 1e9;

vector< tuple<int,int,int> >E;

int n,m;
int a[maxn];
pair<int,int>ai[maxn];

struct edge
{
	int y,c,nex;
}e[maxn<<3]; int len,fir[maxn];
void ins(const int x,const int y,const int c)
{
	e[++len]=(edge){y,c,fir[x]};fir[x]=len;
	e[++len]=(edge){x,0,fir[y]};fir[y]=len;
}
int h[maxn],st,ed;
int bfs()
{
	for(int i=1;i<=ed;i++) h[i]=0;
	h[st]=1;
	queue<int>q; q.push(st);
	while(!q.empty())
	{
		const int x=q.front(); q.pop();
		for(int k=fir[x];k;k=e[k].nex) 
		{
			int y=e[k].y;
			if(e[k].c&&!h[y])
			{
				h[y]=h[x]+1;
				q.push(y);
			}
		}
	}
	return h[ed]>0;
}
int dfs(const int x,const int flow)
{
	if(x==ed) return flow;
	int delta=0;
	for(int k=fir[x];k;k=e[k].nex)
	{
		int y=e[k].y;
		if(e[k].c&&h[y]==h[x]+1)
		{
			int minc= dfs(y,min(e[k].c,flow-delta));
			delta+=minc;
			e[k].c-=minc;
			e[k^1].c+=minc;
		}
		if(delta==flow) 
		{
			return delta;
		}
	}
	if(delta==0) h[x]=0;
	return delta;
}
int Flow()
{
	int ans=0;
	if(bfs())
		ans+=dfs(st,1);
	return ans;
}
int rt,D;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ai[i]=make_pair(a[i],i);
		D=max(D,a[i]);
	}
	sort(ai+1,ai+n+1);
	
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		cin>>u>>v>>l;
		if(u==v) continue;
		E.emplace_back(u,v,l);
	}
	
	if( n>=3 && ai[1].first==ai[3].first )
	{
		cout<<"NO\n";
		return 0;
	}
	rt= ai[1].second;
	
	st=n+n+1,ed=n+n+2; len=1;
	for(int i=1;i<=n;i++) ins(i,n+i,1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==D)
		{
			ins(n+i,ed,1);
		}
	}
	
	vector<int>fa(n+5);
	for(auto [u,v,l]:E)
	{
		if(a[u]>a[v]) swap(u,v);
		if(a[v]-a[u]==l) 
		{
			fa[v]=u;
			ins(u+n,v,1);
		}
	}
	int cnt=0,sp;
	for(int i=1;i<=n;i++) if(i!=rt)
	{
		if(fa[i]==0) cnt++,sp=i;
	}
	
	vector<int>mark(n+5);
	if(cnt>=2) { cout<<"NO\n"; return 0; }
	else if(cnt==1) 
	{
		int ok=0;
		for(auto [u,v,l]:E)
		{
			if(v==rt) swap(u,v);
			if(u==rt&&v==sp && a[u]+a[v]-l==D ) ok=1;
		}
		if(!ok) { cout<<"NO\n"; return 0; }
		
		mark[sp]=1;
	}
	else
	{
		for(auto [u,v,l]:E) if(u==rt||v==rt)
		{
			if(v==rt) swap(u,v);
			if( a[u]+a[v]-l == D ) mark[v]=1;
		}
	}
	
	ins(st,rt,1);
	if(Flow()!=1) { cout<<"NO\n"; return 0; }
	for(int i=1;i<=n;i++) if(mark[i]) ins(st,i,1);
	if(Flow()!=1) { cout<<"NO\n"; return 0; }
	
	vector< tuple<int,int,int> >ans;
	vector<int>flag(n+5);
	for(int k=fir[st];k;k=e[k].nex)
	{
		int y=e[k].y;
		if(e[k].c==0&&y!=rt)
		{
			ans.emplace_back(rt,y, a[rt]+a[y]-D);
			flag[rt]=flag[y]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=fir[i+n];k;k=e[k].nex) if(e[k].c==0&&k%2==0)
		{
			int y=e[k].y;
			if(y!=ed)
			{
				ans.emplace_back(i,y,a[y]-a[i]);
				flag[y]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) if(!flag[i])
		ans.emplace_back(fa[i],i,a[i]-a[fa[i]]);
	
	cout<<"YES\n";
	for(auto [u,v,l]:ans)
		cout<<u<<' '<<v<<' '<<l<<'\n';
	
	return 0;
}

/*
n=2
*/
