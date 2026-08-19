#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,op,x,y,mn,p;
int a[N],b[N],la[N];
set<int>c[N];
ll ans;
struct Segment{ll v;int b;}t[N*4];
void R(int &n){
	char c;
	for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
ll qry2(int v,int l,int r){
	if(mn<=t[v].b)return (ll)mn*(r-l+1);
	if(l==r)return mn=t[v].b;
	int m=l+r>>1;
	if(mn<=t[v*2+1].b)return (ll)mn*(r-m)+qry2(v*2,l,m);
	ll s=t[v].v+qry2(v*2+1,m+1,r);
	mn=min(mn,t[v*2].b);
	return s;
}
ll qry(int v,int l,int r,int pl,int pr){
	if(pl<=l&&r<=pr)return qry2(v,l,r);
	int m=l+r>>1;
	ll s=0;
	if(pr>m)s+=qry(v*2+1,m+1,r,pl,pr);
	if(pl<=m)s+=qry(v*2,l,m,pl,pr);
	return s;
}
void build(int v,int l,int r){
	if(l==r){
		t[v].b=b[l];
		return;
	}
	int m=l+r>>1;
	build(v*2,l,m);build(v*2+1,m+1,r);
	t[v].b=min(t[v*2].b,t[v*2+1].b);
	mn=t[v*2+1].b;t[v].v=qry2(v*2,l,m);
}
void ch(int v,int l,int r,int x,int y){
	if(l==r){
		t[v].b=y;
		return;
	}
	int m=l+r>>1;
	if(x<=m)ch(v*2,l,m,x,y);else ch(v*2+1,m+1,r,x,y);
	t[v].b=min(t[v*2].b,t[v*2+1].b);
	mn=t[v*2+1].b;t[v].v=qry2(v*2,l,m);
}
void find(int v,int l,int r){
	if(t[v].b>=y){
		p=l;
		return;
	}
	if(l==r)return;
	int m=l+r>>1;
	if(t[v*2+1].b>=y){
		p=m+1;
		find(v*2,l,m);
	}else find(v*2+1,m+1,r);
}
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	R(n);R(m);
	fo(i,1,n)R(a[i]),c[a[i]].insert(i);
	fo(i,0,n)c[i].insert(n+1),la[i]=n+1;
	fd(i,1,n)b[i]=la[a[i]]-1,la[a[i]]=i;
	build(1,1,n);
	int qs=0;
	fo(i,1,m){
		R(op);R(x);R(y);
		if(op==1){
			if(a[x]==y)continue;
			set<int>::iterator it=c[a[x]].find(x),it2=it;
			if(c[a[x]].begin()!=it){
				int z=*--it2;
				b[z]=b[x];
				ch(1,1,n,z,b[z]);
			}
			int z=*c[y].begin();
			if(z>x)b[x]=z-1;
			else{
				z=*--c[y].lower_bound(x);
				b[x]=b[z];
				b[z]=x-1;
				ch(1,1,n,z,b[z]);
			}
			ch(1,1,n,x,b[x]);
			c[a[x]].erase(it);
			c[y].insert(x);
			a[x]=y;
		}else{
			p=0;
			find(1,1,n);
			int z=max(min(p,y+1),x);
			ans=(ll)y*(y-z+1)-(ll)(x-1+y-1)*(y-x+1)/2;
			if(x<z)
				mn=1e9,ans+=qry(1,1,n,x,z-1);
			printf("%lld\n",ans);
		}
	}
}