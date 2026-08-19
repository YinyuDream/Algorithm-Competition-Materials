#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define mxn 1048576
#define md 998244353
#define pb push_back
#define mkp make_pair
#define ld long double
#define umap unordered_map
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rept(i,a,b) for(int i=a;i<b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
#define pq priority_queue
using namespace std;
int n,m,k,s,rev[mxn],f[mxn],ans[mxn];
ll inv[50003];
ll power(ll x,int y){
	ll ans=1;
	for(;y;y>>=1){
		if(y&1)ans=ans*x%md;
		x=x*x%md;
	}
	return ans;
}
void ntt(int *a,int n,int flag){
	rept(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int h=1,x,y;h<n;h<<=1){
		int s=power(3,499122176/h);
		for(int j=0;j<n;j+=h<<1){
			ll w=1;
			for(int k=j;k<j+h;++k){
				x=a[k],y=w*a[k+h]%md;
				a[k]=(x+y)%md;
				a[k+h]=(x-y+md)%md;
				w=w*s%md;
			}
		}
	}
	if(flag==-1){
		ll p=power(n,md-2);
		reverse(a+1,a+n);
		rept(i,0,n)a[i]=a[i]*p%md;
	}
}
void initrev(int n){
	int k;
	for(k=0,s=1;s<=n+n;s<<=1,++k);
	rept(i,0,s)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
}
void solve(int n){
	ans[0]=1;
	for(;n;n>>=1){
		if(n&1){
			ntt(ans,s,1);
			ntt(f,s,1);
			rept(i,0,s)ans[i]=(ll)ans[i]*f[i]%md;
			ntt(ans,s,-1);
			ntt(f,s,-1);
			rept(i,k+1,s)ans[i]=f[i]=0;
		}
		ntt(f,s,1);
		rept(i,0,s)f[i]=(ll)f[i]*f[i]%md;
		ntt(f,s,-1);
		rept(i,k+1,s)f[i]=0;
	}
}
signed main(){
	cin>>n>>m>>k;
	if(k&1){
		puts("0");
		return 0;
	}
	inv[1]=1;
	rep(i,2,k)inv[i]=inv[md%i]*(md-md/i)%md;
	ll d=1;
	rep(i,0,k){
		if(i>n)break;
		if(i)d=d*(n-i+1)%md*inv[i]%md;
		if(!(i&1))f[i]=d;
	}
	initrev(k);
	solve(m);
	cout<<ans[k]*power(2,m)%md;
	return 0;
}