#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ls now<<1
#define rs now<<1|1
#define ll long long
using namespace std;
const ll maxn=1000010;
ll mxx[maxn],mxl[maxn],mxr[maxn],sum[maxn];
ll n,m,k,d;
void up(ll now){
	sum[now]=sum[ls]+sum[rs];
	mxx[now]=max(mxx[ls],mxx[rs]);
	mxx[now]=max(mxx[now],mxr[ls]+mxl[rs]);
	mxl[now]=max(mxl[ls],sum[ls]+mxl[rs]);
	mxr[now]=max(mxr[rs],sum[rs]+mxr[ls]);
}
void build(ll now,ll l,ll r){
	if(l==r){
		sum[now]=mxl[now]=mxr[now]=mxx[now]=-k;return;
	}ll mid=l+r>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	up(now);
}
void change(ll now,ll l,ll r,ll pos,ll y){
	if(l==r){mxx[now]+=y;mxl[now]+=y;mxr[now]+=y;sum[now]+=y;return;}
	ll mid=l+r>>1;
	if(pos<=mid)change(ls,l,mid,pos,y);
	if(pos> mid)change(rs,mid+1,r,pos,y);
	up(now);
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);build(1,1,n);
	for(ll i=1;i<=m;i++){
		ll r,x;
		scanf("%lld%lld",&r,&x);
		change(1,1,n,r,x);
		if(mxx[1]>d*k){printf("NIE\n");}
		else printf("TAK\n");
	}
} 
