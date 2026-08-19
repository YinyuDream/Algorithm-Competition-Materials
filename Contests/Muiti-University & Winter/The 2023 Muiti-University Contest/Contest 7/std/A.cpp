#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int mod=998244353;
int C[505][505];
int qp(int a,int b){
	if(b<0){
		return qp(qp(a,mod-2),-b);
	}
	int ans=1;
	while(b){
		if(b&1) (ans*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return ans;
}
struct poly{
	int siz;
	int a[505];
	void setsize(int s){
		siz=s; return ;
	}
	void addp(int pos,int x){
		(a[pos]+=x)%=mod;
	} 
}ept;
poly add(poly x,poly y){
	if(x.siz<y.siz) x.setsize(y.siz);
	for(int i=0;i<y.siz;i++) (x.a[i]+=y.a[i])%=mod;
	return x;
}
poly mnss(poly x,poly y){
	if(x.siz<y.siz) x.setsize(y.siz);
	for(int i=0;i<y.siz;i++) (x.a[i]+=mod-y.a[i])%=mod;
	return x;
}
poly mul(poly x,poly y){
	poly ans=ept; ans.setsize(x.siz+y.siz-1);
	for(int i=0;i<x.siz;i++) for(int j=0;j<y.siz;j++) (ans.a[i+j]+=x.a[i]*y.a[j])%=mod;
	return ans;
}
poly integral(poly x){
	poly ans=ept; ans.setsize(x.siz+1);
	for(int i=0;i<x.siz;i++) ans.a[i+1]=x.a[i]*qp(i+1,-1)%mod;
	return ans;
}
poly del1(poly x){
	poly ans=ept; ans.setsize(x.siz);
	for(int i=0;i<x.siz;i++){
		int mul=1;
		for(int j=i;j>=0;j--){
			(ans.a[j]+=x.a[i]*C[i][j]%mod*mul)%=mod;
			(mul*=(mod-1))%=mod;
			if(j==0) break;
		}
	}
	return ans;
}
int takein(poly x,int a){
	int ans=0,now=1;
	for(int i=0;i<x.siz;i++){
		(ans+=now*x.a[i])%=mod;
		(now*=a)%=mod;
	}
	return ans;
}
void print(poly x){
	cout<<x.siz<<"  ";
	for(int i=0;i<x.siz;i++) cout<<x.a[i]<<" ";
	cout<<"\n";
}
vector<int> vc[505];
int l[505],r[505],gt[1000005],cnt=0;
void build(int l,int r,int now){
	for(int i=l;i<=r;i++){
		if(gt[i]){
			vc[now].push_back(++cnt);
			build(i+1,gt[i]-1,cnt);
			i=gt[i];
		}
	}
}
poly f[505][20];
void dfs(int now){
	if(vc[now].size()==0){
		f[now][0].setsize(2); f[now][0].addp(1,1);
		for(int i=1;i<=11;i++){
			f[now][i].setsize(1); f[now][i].addp(0,1);
		}
		return ;
	}
	for(auto v:vc[now]) dfs(v);
	if(now!=0){
		for(int i=0;i<=11;i++){
			f[now][i].setsize(1); f[now][i].addp(0,1);
			for(auto v:vc[now]) f[now][i]=mul(f[now][i],f[v][i]);
			f[now][i]=integral(f[now][i]);
		}
		for(int i=11;i>=1;i--){
			int mns=takein(f[now][i],i),ad=takein(f[now][i-1],i);
			f[now][i].addp(0,ad+mod-mns);
			f[now][i]=mnss(f[now][i],del1(f[now][i-1]));
		}
	}
	else{
		for(int i=0;i<=11;i++){
			f[now][i].setsize(1); f[now][i].addp(0,1);
			for(auto v:vc[now]) f[now][i]=mul(f[now][i],f[v][i]);
		}
	}
//	for(int i=0;i<=4;i++){
//		cout<<i<<"   "; print(f[now][i]);
//	}
//	cout<<now<<"\n\n";
}
signed main(){
	for(int i=0;i<=500;i++) C[i][0]=1;
	for(int i=1;i<=500;i++) for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	int n,m,t; cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i];
		gt[l[i]]=r[i];
	}
	build(1,n,0);
	dfs(0);
	int inv=qp(1000000,-1);
	while(t--){
		int p,q; cin>>p>>q;
		int P=p*inv%mod,Q=q*inv%mod;
		cout<<(takein(f[0][q/1000000],Q)+mod-takein(f[0][p/1000000],P))%mod<<"\n";
	}
	return 0;
}
