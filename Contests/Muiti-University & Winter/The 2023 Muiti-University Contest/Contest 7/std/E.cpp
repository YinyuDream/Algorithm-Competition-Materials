#include<bits/stdc++.h>
#define ll long long
#define mxn 300003
#define md 1000000007
#define pb push_back
#define mkp make_pair
#define ld long double
#define umap unordered_map
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rept(i,a,b) for(int i=a;i<b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
#define pq priority_queue
using namespace std;
int n,q,tot,b[mxn],c[mxn],vr[mxn];
ll ls,f[mxn],s[mxn];
vector<int>g[mxn];
map<pair<int,int>,int>mp;
signed main(){
    scanf("%d%d",&n,&q);
	int op,x,y;
	while(q--){
		scanf("%d%d",&op,&x),x^=ls;
		if(op==1){
		    scanf("%d",&y),y^=ls;
			pair<int,int>p={min(x,y),max(x,y)};
			if(mp.find(p)!=mp.end()){
				int id=mp[p];
				b[id]++;
				if(b[id]==1){
					if(vr[id]==x)swap(x,y);
					s[y]+=f[x];
				}
				continue;
			}
			if(c[x]>c[y])swap(x,y);
			s[y]+=f[x];
			vr[++tot]=y;
			g[x].pb(tot),c[x]++;
			mp[p]=tot;
			b[tot]=1;
		}else if(op==2){
		    scanf("%d",&y),y^=ls;
			pair<int,int>p={min(x,y),max(x,y)};
			int id=mp[p];
			b[id]--;
			if(!b[id]){
				if(vr[id]==x)swap(x,y);
				s[y]-=f[x];
			}
		}else if(op==3){
		    scanf("%d",&y),y^=ls;
			f[x]+=y;
			for(int i:g[x])if(b[i])s[vr[i]]+=y;
		}else{
			ls=f[x]+s[x];
			for(int i:g[x])if(b[i])ls+=f[vr[i]];
			printf("%lld\n",ls);
			ls&=1073741823;
		}
	}
	return 0;
}
