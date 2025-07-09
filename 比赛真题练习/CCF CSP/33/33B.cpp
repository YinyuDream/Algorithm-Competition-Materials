#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,bing,jiao;
set<string>st,a,b;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string word;
		cin>>word;
		int len=word.size();
		for(int j=0;j<len;j++){
			if(word[j]>='A'&&word[j]<='Z')
				word[j]=word[j]-'A'+'a';
		}
		st.insert(word);
		b.insert(word);
	}
	for(int i=1;i<=m;i++){
		string word;
		cin>>word;
		int len=word.size();
		for(int j=0;j<len;j++){
			if(word[j]>='A'&&word[j]<='Z')
				word[j]=word[j]-'A'+'a';
		}
		st.insert(word); 
		a.insert(word);
	}
	bing=st.size();
	for(auto i:st){
		if(b.find(i)!=b.end()&&a.find(i)!=a.end())
		jiao++;
	}
	cout<<jiao<<"\n"<<bing;
	return 0;
}