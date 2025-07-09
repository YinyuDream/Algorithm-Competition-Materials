#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
map<string,string>s;
string getans(string n){
	
	if (s.find(n) != s.end()) {
		return s[n];
	} 
	if (n.substr(n.size() - 6) == ".first") {
		string base = n.substr(0, n.size() - 6); 
		string baseType = getans(base);
		int commaPos;
         ll a=0;
		for(int i=baseType.size()-1;i>=0;i--){
			if(baseType[i]==','&&a==1){
				commaPos=i;
				break;
			}
            if(baseType[i]=='>'){
                a++;
            }
            if(baseType[i]=='<'){
                a--;
            }
		}
	//	cout<<baseType.substr(5, commaPos - 5);
		return baseType.substr(5, commaPos - 5);
	} 
	else{
		string base = n.substr(0, n.size() - 7); 
		string baseType = getans(base);
		int commaPos;
        ll a=0;
		for(int i=baseType.size()-1;i>=0;i--){
			if(baseType[i]==','&&a==1){
				commaPos=i;
				break;
			}
            if(baseType[i]=='>'){
                a++;
            }
            if(baseType[i]=='<'){
                a--;
            }
		}
	//	cout<< baseType.substr(commaPos + 1, baseType.size() - commaPos - 2);
		return baseType.substr(commaPos + 1, baseType.size() - commaPos - 2);
	}
	return "";
}
void solve(){
	ll a,b;
	cin>>a>>b;
	while(a--){
		string type,name;
		cin>>type>>name;
		name.pop_back();
		s[name]=type;
	}
	while(b--){
		string name;
		cin>>name;
		cout<<getans(name)<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--) {
		solve();
	}
	
	return 0;
}