#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define ll int
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
void solve(){
	ll n;
	cin>>n;
	ll q;
	cin>>q;
	vector<pii>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].f>>v[i].s;
	}
	vector<vector<pii>>mpnum(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			pii x;
			x.f=v[i].f-v[j].f;
			x.s=v[i].s-v[j].s;
			ll gcd=abs(__gcd(x.f,x.s));
			x.f/=gcd;
			x.s/=gcd;
			if(x.f<0){
				x.f=-x.f;
				x.s=-x.s;
			}
			if(x.f==0){
				x.s=1;
			}
			if(x.s==0){
				x.f=1;
			}
			mpnum[i].push_back(x);
		}
		sort(mpnum[i].begin(),mpnum[i].end());
	}
	while(q--){
		ll ans=0;
		ll a,b;
		cin>>a>>b;
		vector<pii>newmp;
		vector<pii>ww(n);
		for(int i=0;i<n;i++){
			ww[i]={a-v[i].f,b-v[i].s};
		}
		for(auto &x:ww){
			ll gcd=__gcd(x.f,x.s);
			x.f/=gcd;
			x.s/=gcd;
			if(x.f<0){
				x.f=-x.f;
				x.s=-x.s;
			}
			if(x.f==0){
				x.s=1;
			}
			if(x.s==0){
				x.f=1;
			}
			newmp.push_back(x);
		}
		sort(newmp.begin(),newmp.end());
		for(auto x:ww){
			pii p={x.s,-x.f};
			if(p.f<0){
				p.f=-p.f;
				p.s=-p.s;
			}
			if(p.f==0){
				p.s=abs(p.s);
			}
			ll posa=lower_bound(newmp.begin(),newmp.end(),p)-newmp.begin();
			ll posb=upper_bound(newmp.begin(),newmp.end(),p)-newmp.begin();
			ans+=posb-posa;
		}
		ans/=2;
		for(int i=0;i<n;i++){
			pii x;
			x.f=a-v[i].f;
			x.s=b-v[i].s;
			ll gcd=__gcd(x.f,x.s);
			x.f/=gcd;
			x.s/=gcd;
			if(x.f<0){
				x.f=-x.f;
				x.s=-x.s;
			}
			if(x.f==0){
				x.s=1;
			}
			if(x.s==0){
				x.f=1;
			}
			pii p={x.s,-x.f};
			if(p.f<0){
				p.f=-p.f;
				p.s=-p.s;
			}
			if(p.f==0){
				p.s=abs(p.s);
			}
			ll posa=lower_bound(mpnum[i].begin(),mpnum[i].end(),p)-mpnum[i].begin();
			ll posb=upper_bound(mpnum[i].begin(),mpnum[i].end(),p)-mpnum[i].begin();
			ans+=posb-posa;
		}
		cout<<ans<<'\n';
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t=1;
	while(t--){
		solve();
	}
}