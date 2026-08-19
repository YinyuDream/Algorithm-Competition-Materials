#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
void solve(){
	ll n;
	cin>>n;
	vector<int>v,w;
	int a,b;
	a=b=0;
	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		if(t>=0){
			a++;
			w.push_back(t);
		}
		else{
			b++;
			v.push_back(t);
		}
	}
	for(int i=0;i<b;i++){
		if(b-1-i<=i)break;
		swap(v[i],v[b-1-i]);
	}
	int i=0;
	int pos=a-1;
	int now=0;
	int ans=0;
	stack<int>s;
	while(i<=pos){
		if(now==w[i]){
			s.push(-1);
			ans++;
			i++;
		}
		else{
			s.push(0);
			pos--;
			now++;
		}
	}
	int j=0;
	int ppos=b-1;
	int nnow=0;
	int anss=0;
	int maxs=ans;
	while(j<=ppos){
		if(nnow==v[j]){
			anss++;
			j++;
		}
		else{
			ppos--;
			nnow--;
            	if(!s.empty()){
			ans+=s.top();
			s.pop();
		}
		else{
			ans=0;
		}
		}
	
		maxs=max(maxs,ans+anss);
	}
	i=0;
	pos=b-1;
	now=0;
	ans=0;
	while(!s.empty()){
		s.pop();
	}
	while(i<=pos){
		if(now==v[i]){
			s.push(-1);
			ans++;
			i++;
		}
		else{
			s.push(0);
			pos--;
			now--;
		}
	}
	j=0;
	ppos=a-1;
	nnow=0;
	anss=0;
	while(j<=ppos){
		if(nnow==w[j]){
			anss++;
			j++;
		}
		else{
			ppos--;
			nnow++;
        if(!s.empty()){
			ans+=s.top();
			s.pop();
		}
		else{
			ans=0;
		}
		}
	
		maxs=max(maxs,ans+anss);
	}
	cout<<maxs<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--) {
		solve();
	}
	
	return 0;
}