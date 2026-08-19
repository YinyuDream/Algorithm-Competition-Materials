#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

string s[405],t;
vector<string> vv[405],vv2;
ll ans=0,pw[405];
const ll mod=998244353;

void dfs(ll pos){
	if (pos>20)return;
	bool ok=0;
	for (string i:vv[pos]){
		bool f=1;
		for (ll j=0;j<pos;j++){
			if (i[j]=='?'||i[j]==t[j]){
				continue;
			}else{
				f=0;
				break;
			}
		}
		if (f){
			ok=1;
			break;
		}
	}
	if (ok){
		ans+=ok;
	}
	
	t+='0';
	dfs(pos+1);
	t.pop_back();
	t+='1';
	dfs(pos+1);
	t.pop_back();
}

int main(){
	ll n;
	cin >> n;
	for (ll i=1;i<=n;i++){
		cin >> s[i];
		if (s[i].length()<=20){
			vv[s[i].length()].push_back(s[i]);
		}else{
			vv2.push_back(s[i]);
		}
	}
	pw[0]=1;
	for (ll i=1;i<=400;i++)pw[i]=pw[i-1]*2%mod;
	dfs(0);
	
	for (ll i=0;i<=(1<<vv2.size())-1;i++){
		string s="";
		ll tot=0;
		for (ll j=0;j<vv2.size();j++){
			if (i>>j&1){
				if (s.empty()){
					s=vv2[j];
				}else{
					if (vv2[j].length()!=s.length()){
						goto oo;
					}
					for (ll k=0;k<s.length();k++){
						if (s[k]=='?'||vv2[j][k]=='?')s[k]='?';
						else if (s[k]!=vv2[j][k])goto oo;
					}
				}
			}
			
		}
		if (s.empty())continue;
		for (char j:s)if (j=='?')tot++;
//		cout<<i<<":"<<s<< endl;
		if (__builtin_popcount(i)&1)
		ans+=pw[tot];
		else
		ans-=pw[tot];
		ans+=mod;
		ans%=mod;oo:;
	}
	cout<< ans;
	return 0;
}

/*
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　■■■■■　　　　　■■　　　　　　■■■　　　　　■■■　　　■　　　　■　　　　　■　　　　　■■■■　　　　■■■■　　
　■　　　■■　　　　■■　　　　　■　　■■　　　■　　■■　　■　　　　■　　　　■■　　　　　■　　■■　　■■　　■　　
　■　　　　■　　　　■■　　　　■　　　　■　　■　　　　■　　　■　　■　　　　■■■　　　　■■　　■■　　■　　　■■　
　■　　　　■　　　　■■　　　　■　　　　■　　■　　　　■　　　■　　■　　　　　■■　　　　■　　　■■　　　　　　■■　
　■　　　　■　　　　■■　　　　■　　　　　　　■　　　　　　　　　■■　　　　　　■■　　　　　　　　■■　　　　　　■　　
　■　　　■■　　　　■■　　　　■　　■■■　　■　　■■■　　　　■■　　　　　　■■　　　　　　　■■　　　　　■■■　　
　■■■■■　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　　■■　　　　　　　　■■　
　■　　　　　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　■■　　　　　　　　　　■　
　■　　　　　　　　　■■　　　　■　　　　■　　■　　　　■　　　　■■　　　　　　■■　　　　　■　　　　　　■　　　■■　
　■　　　　　　　　　■■　　　　■■　　■■　　■■　　■■　　　　■■　　　　　　■■　　　　■　　　　　　　■■　　■■　
　■　　　　　　　　　■■　　　　　　■■■■　　　　■■■■　　　　■■　　　　　　■■　　　　■■■■■■　　　■■■■　　
*/
