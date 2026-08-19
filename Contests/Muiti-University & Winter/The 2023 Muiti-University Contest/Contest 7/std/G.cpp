#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
int read(){int x;scanf("%lld",&x);return x;}
void print(int x){printf("%lld\n",x);}
void file(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int mod=998244353;
int n,m,k;
int a[1000005];
bool vis[1000005];
int b[1000005];
int x[1000005];
bool calc()
{
	if(m&1)
	{
		int tot=accumulate(b+1,b+m+1,0ll);
		if(tot&1){return 0;}
		tot/=2;
		int sm=0;
		rep1(i,m){sm+=(i&1)*b[i];}
		x[m]=sm-tot;
		for(int i=m;i>=2;i--)
		{
			x[i-1]=b[i]-x[i];
		}
		return *min_element(x+1,x+m+1)>=0;
	}
	int o=0,e=0;
	rep1(i,m)
	{
		if(i&1){o+=b[i];}
		else{e+=b[i];}
	}
	if(o^e){return 0;}
	int ulim=b[2],dlim=0;
	int cur=b[2];
	for(int i=3;i<=m;i++)
	{
		if(i&1){cur-=b[i];dlim=max(dlim,cur);}
		else{cur+=b[i];ulim=min(ulim,cur);}
	}
	return dlim<=ulim;
}
void solve()
{
	n=read(),k=read();
	rep1(i,n){a[i]=read();}
	if(k>n/2)
	{
		if(!(*max_element(a+1,a+n+1))){puts("YES");}
		else{puts("NO");}
		return;
	}
	bool ok=1;
	rep1(i,n){vis[i]=0;}
	rep1(i,n)
	{
		if(!vis[i])
		{
			m=0;
			int cur=i;
			while(!vis[cur])
			{
				vis[cur]=1;b[++m]=a[cur];
				if((cur+k)%n==0){cur=n;}
				else{cur=(cur+k)%n;}
			}
			ok&=calc();
		}
	}
	puts((ok?"YES":"NO"));
}
signed main()
{
	int t=read();
	while(t--){solve();}
	return 0;
}
